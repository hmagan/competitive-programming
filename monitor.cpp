#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int heights[n];
		for(int i = 0; i < n; i++){
			cin >> heights[i];
		}
		sort(heights, heights + n);
		int h1_num = -1; //max
		int h2_num = 10e6; //min
		
		int idx = 0;
		while(idx < n){
			int num = heights[idx];
			int count = 1;
			while(heights[idx] == heights[idx+1]){
				count++;
				idx++;
			}
			idx++;
			h1_num = max(h1_num, count);
			h2_num = min(h2_num, count);
		}
		if(h1_num == h2_num){
			cout << "-1\n";
		} else {
			cout << h1_num - h2_num << "\n";
		}
	}
}