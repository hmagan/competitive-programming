#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int cows[n];
	int heights[n];
	
	for(int i = 0; i < n; i++){
		cin >> cows[i];
	}
	for(int i = 0; i < n; i++){
		cin >> heights[i];
	}
	
	sort(cows, cows + (sizeof(cows) / sizeof(cows[0])));
	sort(heights, heights + (sizeof(heights) / sizeof(heights[0])));
	
	int j;
	long long answer = 1;
	
	for(int i = 0; i < n; i++){
		j = 0;
		while(j < n && heights[n-j-1] >= cows[n-i-1]){
			j++;
		}
		answer *= j - i;
	}
	
	cout << answer;
}