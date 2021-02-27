#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ifstream fin ("photo.in");
	ofstream fout ("photo.out");
	
	int n;
	fin >> n;
	
	int cows[n-1];
	for(int i = 0; i < n-1; i++){
		fin >> cows[i];
	}
	
	int answer[n];
	for(int i = 1; i <= n; i++){
		int output[n];
		output[0] = i;
		bool bad = false;
		for(int j = 1; j < n; j++){
			output[j] = cows[j-1] - output[j-1];
			if(output[j] < 0 || output[j] > n){
				bad = true;
				break;
			}
		}
		if(bad){
			continue;
		}
		bool repeats = false;
		for(int j = 0; j < n; j++){
			for(int k = j + 1; k < n; k++){
				if(output[j] == output[k]){
					repeats = true;
					break;
				}
			}
			if(repeats){
				break;
			}
		}
		if(!repeats){
			for(int j = 0; j < n; j++){
				answer[j] = output[j];
			}
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(i == n-1){
			fout << answer[i];
			break;
		}
		fout << answer[i] << " ";
	}
	
	return 0;
}