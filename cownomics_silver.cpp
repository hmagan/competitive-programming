#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("cownomics.in");
	ofstream fout ("cownomics.out");
	
	int n, m;
	fin >> n >> m;
	
	string spotty[n];
	string plain[n];
	
	for(int i = 0; i < n; i++){
		fin >> spotty[i];
	}
	for(int i = 0; i < n; i++){
		fin >> plain[i];
	}
	
	int count = 0;
	//quintuple for loop B)
	//misses 2 cases for TLE but solid for bronze problem solving
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			for(int k = j + 1; k < m; k++){
				bool good = true;
				for(int l = 0; l < n; l++){
					for(int o = 0; o < n; o++){
						if(spotty[l][i] == plain[o][i] && spotty[l][j] == plain[o][j] && spotty[l][k] == plain[o][k]){
							good = false;
							break;
						}
					}
					if(!good){
						break;
					}
				}
				if(good){
					count++;
				}
			}
		}
	}
	
	fout << count;
}