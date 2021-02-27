#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("factory.in");
	ofstream fout ("factory.out");
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	int n;
	fin >> n;
	
	int belts[n-1][2];
	for(int i = 0; i < n - 1; i++){
		fin >> belts[i][0] >> belts[i][1];
	}
	
	int station = -1;
	for(int i = 1; i <= n; i++){
		bool good = true;
		for(int j = 1; j <= n; j++){
			bool done = false;
			if(i == j){
				continue;
			}
			int idx = -1;
			for(int k = 0; k < n - 1; k++){
				if(belts[k][0] == j){
					idx = k;
					break;
				}
			}
			if(idx == -1){
				good = false;
				break;
			}
			while(true){
				int further = belts[idx][1];
				if(further == i){
					break;
				}
				int next = -1;
				for(int k = 0; k < n - 1; k++){
					if(belts[k][0] == further){
						next = k;
						idx = k;
						break;
					}
				}
				if(next == -1){
					done = true;
					break;
				}
			}
			if(done){
				good = false;
				break;
			}
		}
		if(good){
			station = i;
			break;
		}
	}
	
	fout << station;
	
	return 0;
}