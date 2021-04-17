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
		
		int min_val = 9999999;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				min_val = min(min_val, ((a[i] & a[j]) ^ (a[i] | a[j])));
			}
		}
		
		cout << min_val << "\n";
	}
}