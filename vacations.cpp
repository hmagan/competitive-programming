#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	//dynamic programming approach
	//seemingly doable with a greedy algorithm
	// 0 = rest, 1 = contest, 2 = gym
	int dp[n][3];
	for(int i = 0; i < n; i++){
		dp[i][0] = n;
		dp[i][1] = n;
		dp[i][2] = n;
	}
	dp[0][0] = 1;
	
	int a;
	cin >> a;
	if(a == 1 || a == 3){
		dp[0][1] = 0;
	}
	if(a == 2 || a == 3){
		dp[0][2] = 0;
	}
	
	for(int i = 1; i < n; i++){
		cin >> a;
		dp[i][0] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
		
		if(a == 1 || a == 3){
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
		}
		if(a == 2 || a == 3){
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
		}
		//cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
	}
	
	cout << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << "\n";
}