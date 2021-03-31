#include <bits/stdc++.h>

using namespace std;

int main()
{
	string animals[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
	
	int n;
	cin >> n;
	
	vector<vector<string>> orig_cows;
	for(int i = 0; i < n; i++){
		vector<string> temp;
		
		string born_cow, prev, animal, other_cow;
		string useless, temporary, stupid, variables;
		
		cin >> born_cow >> useless >> temporary >> prev >> animal >> stupid >> variables >> other_cow;
		
		temp.push_back(born_cow);
		temp.push_back(prev);
		temp.push_back(animal);
		temp.push_back(other_cow);
		
		orig_cows.push_back(temp);
	}
	
	vector<vector<string>> cows;
	for(int i = 0; i < orig_cows.size(); i++){
		if(orig_cows[i][0] == "Elsie"){
			cows.push_back(orig_cows[i]);
			int idx = i;
			while(true){
				int t_idx = -1;
				for(int j = 0; j < orig_cows.size(); j++){
					if(orig_cows[idx][3] == orig_cows[j][0]){
						cows.insert(cows.begin(), orig_cows[j]);
						t_idx = j;
						idx = j;
					}
				}
				if(t_idx == -1 || cows[0][3] == "Bessie"){
					break;
				}
			}
			break;
		}
	}
	
	int years = 0;
	int prev_animal = 0;
	for(int i = 0; i < cows.size(); i++){
		if(cows[i][1] == "previous"){
			int count = 0;
			while(true){
				if(prev_animal < 0){
					prev_animal = 11;
				}
				if(animals[prev_animal] == cows[i][2]){
					break;
				}
				prev_animal--;
				count++;
			}
			years -= count;
		} else {
			int count = 0;
			while(true){
				if(prev_animal > 11){
					prev_animal = 0;
				}
				if(animals[prev_animal] == cows[i][2]){
					break;
				}
				prev_animal++;
				count++;
			}
			years += count;
		}
	}
	
	cout << abs(years);
}