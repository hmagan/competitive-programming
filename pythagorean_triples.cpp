#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	if(n <= 2){
		cout << "-1\n";
	} else if (n == 3){
		cout << "4 5\n";
	} else if(n % 2){
		long long num = (n - 1) / 2;
		cout << 2 * num * num + 2 * num << " " << 2 * num * num + 2 * num + 1 << "\n";
	} else {
		cout << n / 2 * n / 2 - 1 << " " << n / 2 * n / 2 + 1 << "\n";
	}
}
