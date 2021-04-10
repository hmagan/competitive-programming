#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		char grid[n][n];
		int loc[2][2];
		bool good = true;
		for(int i = 0; i < n; i++){
			string row;
			cin >> row;
			for(int j = 0; j < n; j++){
				char x = row[j];
				if(x == '*'){
					if(good){
						loc[0][0] = i;
						loc[0][1] = j;
						good = false;
					} else {
						loc[1][0] = i;
						loc[1][1] = j;
					}
				}
				grid[i][j] = x;
			}
		}
		if(loc[0][0] == loc[1][0]){
			if(loc[0][0] == 0){
				grid[loc[0][0]+1][loc[0][1]] = '*';
				grid[loc[0][0]+1][loc[1][1]] = '*';
			} else {
				grid[loc[0][0]-1][loc[0][1]] = '*';
				grid[loc[0][0]-1][loc[1][1]] = '*';
			}
		} else if(loc[0][1] == loc[1][1]){
			if(loc[0][1] == 0){
				grid[loc[0][0]][loc[0][1]+1] = '*';
				grid[loc[1][0]][loc[0][1]+1] = '*';
			} else {
				grid[loc[0][0]][loc[0][1]-1] = '*';
				grid[loc[1][0]][loc[0][1]-1] = '*';
			}
		} else {
			grid[loc[0][0]][loc[1][1]] = '*';
			grid[loc[1][0]][loc[0][1]] = '*';
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << grid[i][j];
			}
			cout << "\n";
		}
	}
}