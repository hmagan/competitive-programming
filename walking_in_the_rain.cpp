#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int MIN = min(a[0], a[n-1]);

	for(int i = 1; i < n-2; i++){
		int bigger = max(a[i], a[i+1]);
		MIN = min(MIN, bigger);
	}

	cout << MIN << "\n";
}
