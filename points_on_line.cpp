#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, d;
	cin >> n >> d;

	vector<long long> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}	

	long long ans = 0;
	for(int i = 0; i < n-2; i++){
		int l = i+2;
		int r = n-1;
		while(l + 1 < r){
			int m = (l + r) / 2;
			if(x[m] - x[i] <= d){
				l = m;
			} else {
				r = m;
			}
		}
		if(x[r] - x[i] <= d){
			l = r;
		}
		if(x[l] - x[i] <= d){
			if(l - i == 2){
				ans++;
			} else {
				long long t = l - (i + 1);
				ans += t * (t + 1) / 2;
			}
		}	
	}
	cout << ans << "\n";
}
