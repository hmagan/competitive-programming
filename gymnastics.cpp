#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("gymnastics.in");
	ofstream fout ("gymnastics.out");
	
	int k, n;
	fin >> k >> n;
	
	int cows[k][n];
	
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			fin >> cows[i][j];
		}
	}
	
	bool less;
	int first, second;
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			bool good = true;
			less = i < j;
			first = cows[0][i];
			second = cows[0][j];
			for(int l = 1; l < k; l++){
				int idx_i, idx_j = -1;
				for(int m = 0; m < n; m++){
					if(cows[l][m] == first){
						idx_i = m;
					}
					if(cows[l][m] == second){
						idx_j = m;
					}
				}
				if(less){
					if(idx_i > idx_j){
						good = false;
						break;
					}
				} else {
					if(idx_i < idx_j){
						good = false;
						break;
					}
				}
			}
			if(good){
				count++;
			}
		}
	}
	
	fout << count;
}