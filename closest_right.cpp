#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	while(k--){
		int x;
		cin >> x;
		
		int l = -1;
		int r = n;
		while(r > l + 1){
			int m = (l + r)/2;
			if(a[m] >= x){
				r = m;
			} else {
				l = m;
			}
		}
		
		cout << r + 1 << "\n";
	}
}