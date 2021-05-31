#include <bits/stdc++.h>

using namespace std;

long long MOD = 1073741824;

int n_divisors(long long x){
	int count = 0;
	for(int i = 1; i <= sqrt(x); i++){
		if(x % i == 0){
			count++;
			if(x / i != i){
				count++;
			}
		}
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> d(a * b * c + 1, -1);
	long long ans = 0;
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			for(int k = 1; k <= c; k++){
				int x = i * j * k;
				if(d[x] == -1){
					d[x] = n_divisors(x);
				}
				ans += d[x];
				ans %= MOD;
			}
		}
	}

	cout << ans << "\n";
}
