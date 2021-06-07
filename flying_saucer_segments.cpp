#include <bits/stdc++.h>

using namespace std;

long long n, m;

long long bin_pow(long long a, long long b){
	long long result = 1;
	while(b > 0){
		if(b&1){
			result *= a;
			result %= m;
		}
		a *= a;
		a %= m;
		b /= 2;
	}
	if(result == 0){
		result = m;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;	
	cout << (bin_pow(3, n) - 1) << "\n";
}
