#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		int orig[n];
		for(int i = 0; i < n; i++){
			cin >> orig[i];
		}

		int a[n];
		int idx = k;
		idx %= n;
		for(int i = 0; i < n; i++){
			a[idx] = orig[i];
			idx++;
			idx %= n;
		}

		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}