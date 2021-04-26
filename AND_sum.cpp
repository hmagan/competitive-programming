#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	long long mod = 1e9+7;
	while(t--){
		int n, k;
		cin >> n >> k;
		long long p = 1;
		for(int i = 0; i < k; i++){
			p = (p * n) % mod;
		}
		cout << p << "\n";
	}
}