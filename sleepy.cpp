#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ifstream fin ("sleepy.in");
	ofstream fout ("sleepy.out");
	
	int n;
	fin >> n;
	
	int cows[n];
	for(int i = 0; i < n; i++){
		fin >> cows[i];
	}
	
	int ans = n - 1;
	for(int i = n-2; i>=0; i--){
		if(cows[i] < cows[i+1]){
			ans = i;
		} else {
			break;
		}
	}
	
	fout << ans;
	
	return 0;
}