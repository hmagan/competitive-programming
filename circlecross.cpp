#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("circlecross.in");
	ofstream fout ("circlecross.out");
	
	string names[26];
	int places[26][2];
	
	string cows;
	fin >> cows;
	for(int i = 0; i < 26; i++){
		char curr;
		int l, u;
		for(int j = 0; j < 52; j++){
			if(cows[j] - 'A' == i){
				curr = cows[j];
				l = j;
				break;
			}
		}
		for(int j = l + 1; j < 52; j++){
			if(cows[j] - 'A' == i){
				u = j;
				break;
			}
		}
		names[i] = curr;
		places[i][0] = l;
		places[i][1] = u;
	}
	
	int count = 0;
	for(int i = 0; i < 26; i++){
		for(int j = i + 1; j < 26; j++){
			//see if any overlap
			if(!((places[i][0] > places[j][0] && places[i][1] < places[j][1]) || (places[j][0] > places[i][0] && places[j][1] < places[i][1]))){
				if((places[i][0] < places[j][0] && places[i][1] > places[j][0]) || (places[j][0] > places[i][0] && places[j][0] < places[i][1]) || (places[j][0] < places[i][0] && places[j][1] > places[i][0]) || (places[i][0] > places[j][0] && places[i][0] < places[j][1])){
					count++;
				}
			}
		}
	}
	fout << count;
}