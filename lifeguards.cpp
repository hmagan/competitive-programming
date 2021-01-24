#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("lifeguards.in");
	ofstream fout ("lifeguards.out");
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	fin >> n;
	
	int lifeguards[n][2];
	
	for(int i = 0; i < n; i++){
		fin >> lifeguards[i][0] >> lifeguards[i][1];
	}
	
	int max_time = 0;
	
	//brute force
	for(int i = 0; i < n; i++){
		int time = 0;
		for(int j = 1; j <= 1000; j++){
			for(int k = 0; k < n; k++){
				if(k == i){
					continue;
				}
				if(j >= lifeguards[k][0] && j < lifeguards[k][1]){
					time++;
					break;
				}
			}
		}
		if(time > max_time){
			max_time = time;
		}
	}
	
	fout << max_time;
	
	return 0;
}