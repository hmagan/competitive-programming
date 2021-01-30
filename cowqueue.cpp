#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("cowqueue.in");
	ofstream fout ("cowqueue.out");
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	fin >> n;
	
	int time[n];
	int dur[n];
	
	for(int i = 0; i < n; i++){
		int x, y;
		fin >> x >> y;
		time[i] = x;
		dur[i] = y;
	}
	
	//selection sort
	for(int i = 0; i < n-1; i++){
		int m = i;
		for(int j = i + 1; j < n; j++){
			if(time[j] < time[m]){
				m = j;
			}
		}
		if(m != i){
			int temp = time[i];
			time[i] = time[m];
			time[m] = temp;
			temp = dur[i];
			dur[i] = dur[m];
			dur[m] = temp;
		}
	}
	
	for(int i = 0; i < n-1; i++){
		if(time[i] + dur[i] >= time[i+1]){
			time[i+1] = time[i] + dur[i];
		}
	}
	
	fout << time[n-1] + dur[n-1];
	
	return 0;
}