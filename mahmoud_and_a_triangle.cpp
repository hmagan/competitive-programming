#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	

	bool good = false;
	sort(a.begin(), a.end());
	for(int i = 1; i < n-1; i++){
		if(a[i] + a[i-1] > a[i+1]){
			good = true;
			break;
		}
	}

	cout << ((good) ? "YES\n" : "NO\n") << "\n";
}
