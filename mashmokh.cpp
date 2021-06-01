#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long n, a, b;
	cin >> n >> a >> b;

	long double inc = a / (long double) b;

	while(n--){
		unsigned long long x;
		cin >> x;
	
		cout << ((a * x) % b) / a << " ";
	}	
	cout << "\n";
}
