#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("lineup.in");
    ofstream cout("lineup.out");
	
	string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
	vector<vector<string>> possible;
	int n;
	cin >> n;
	
	string pairs[n][2];
	for(int i = 0; i < n; i++){
		string x, must, be, milked, beside, y;
		cin >> x >> must >> be >> milked >> beside >> y;
		
		pairs[i][0] = x;
		pairs[i][1] = y;
	}
	
	//brute force lol
	do {
		bool good = true;
        for(int i = 0; i < n; i++){
			int one = -1, two = -1;
			for(int j = 0; j < 8; j++){
				if(cows[j] == pairs[i][0]){
					one = j;
				}
				if(cows[j] == pairs[i][1]){
					two = j;
				}
			}
			if(abs(one-two)>= 2){
				good = false;
				break;
			}
		}
		if(good){
			vector<string> temp;
			for(int i = 0; i < 8; i++){
				temp.push_back(cows[i]);
			}
			possible.push_back(temp);
		}
    } while (next_permutation(cows, cows + 8));
	
	vector<string> top = possible[0];
	for(int i = 1; i < possible.size(); i++){
		//cout << "I: " << i << "\n";
		for(int j = 0; j < 8; j++){
			//cout << "J: " << j << "\n";
			if(top[j] > possible[i][j]){
				copy(possible[i].begin(), possible[i].end(), back_inserter(top));
				break;
			}
		}
	}
	
	for(int i = 0; i < 8; i++){
		cout << top[i] << "\n";
	}
}