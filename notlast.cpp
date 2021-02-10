#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("notlast.in");
	ofstream fout ("notlast.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	fin >> n;
	
	string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
	int milk[7];
	
	for(int i = 0; i < 7; i++){
		milk[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		string cow;
		int m, idx = -1;
		fin >> cow >> m;
		
		for(int j = 0; j < 7; j++){
			if(cows[j] == cow){
				idx = j;
				break;
			}
		}
		milk[idx] += m;
	}
	
	int minimum, second = INT_MAX;
	
	for(int i = 0; i < 7; i++){
		//if this print statement isnt here, the program doesnt work ??
		//c++ is wack
		fout << "";
		if(milk[i] < minimum){
			minimum = milk[i];
		}
	}
	
	int idx = -1;
	bool tie = false;
	for(int i = 0; i < 7; i++){
		if(milk[i] != minimum && milk[i] < second){
			second = milk[i];
			idx = i;
		}
	}
	
	for(int i = 0; i < 7; i++){
		if(i != idx && milk[i] == second){
			tie = true;
			break;
		}
	}

	if(tie){
		fout << "Tie\n";
	} else {
		fout << cows[idx] << "\n";
	}
	
	return 0;
}