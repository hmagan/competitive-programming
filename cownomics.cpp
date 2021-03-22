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
	for(int i = 0; i < m; i++){
		bool good = true;
		for(int j = 0; j < n; j++){
			bool good2 = false;
			for(int k = 0; k < n; k++){
				if(spotty[j][i] == plain[k][i]){
					good2 = true;
					break;
				}
			}
			if(good2){
				good = false;
				break;
			}
		}
		if(good){
			count++;
		}
	}
	fout << count;
}