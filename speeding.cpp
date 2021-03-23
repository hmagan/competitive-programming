#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("speeding.in");
    ofstream fout("speeding.out");
	
	int n, m;
	fin >> n >> m;
	
	int limits[n][2];
	int speeds[m][2];
	
	for(int i = 0; i < n; i++){
		fin >> limits[i][0] >> limits[i][1];
	}
	for(int i = 0; i < m; i++){
		fin >> speeds[i][0] >> speeds[i][1];
	}
	
	int idx_limit = 0;
	int idx_speed = 0;
	int max = 0;
	int curr_l = 0;
	int curr_s = 0;
	for(int i = 1; i <= 100; i++){
		if(speeds[idx_speed][1] - limits[idx_limit][1] > max){
			max = speeds[idx_speed][1] - limits[idx_limit][1];
		}
		curr_l++;
		curr_s++;
		if(curr_l == limits[idx_limit][0]){
			idx_limit++;
			curr_l = 0;
		}
		if(curr_s == speeds[idx_speed][0]){
			idx_speed++;
			curr_s = 0;
		}
		if(speeds[idx_speed][1] - limits[idx_limit][1] > max){
			max = speeds[idx_speed][1] - limits[idx_limit][1];
		}
	}
	
	fout << max;
	
	return 0;
}