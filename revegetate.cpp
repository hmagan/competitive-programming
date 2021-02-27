#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("revegetate.in");
	ofstream fout ("revegetate.out");
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	int n, m;
	fin >> n >> m;
	
	vector<vector<int>> spots;
	int output[n];
	int cows[m][2];
	
	for(int i = 0; i < n; i++){
		spots.push_back(vector<int>());
	}
	
	for(int i = 0; i < m; i++){
		int x, y;
		fin >> x >> y;
		
		spots[x-1].push_back(i);
		spots[y-1].push_back(i);
		
		cows[i][0] = x;
		cows[i][1] = y;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= 4; j++){
			bool good = true;
			for(int k = 0; k < spots[i].size(); k++){
				if(i == 0){
					break;
				}
				int other;
				bool done = false;
				for(int l = 0; l < spots.size(); l++){
					for(int o = 0; o < spots[l].size(); o++){
						if(l == i){
							break;
						}
						if(spots[l][o] == spots[i][k]){
							other = l;
							done = 1 == 1;
							break;
						}
					}
					if(done){
						break;
					}
				}
				if(other < i && output[other] == j){
					good = false;
					break;
				}
			}
			if(good){
				output[i] = j;
				break;
			} else {
				output[i] = 9;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		fout << output[i];
	}
	
	return 0;
}