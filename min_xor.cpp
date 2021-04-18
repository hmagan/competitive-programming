#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		sort(a, a + n);

		int min_val = 9999999;
		for(int i = 0; i < n-1; i++){
			min_val = min(min_val, a[i] ^ a[i+1]);
		}
		
		cout << min_val << "\n";
	}
}