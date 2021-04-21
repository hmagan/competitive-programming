#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		int idx = -1;
		for(int i = 0; i < n; i++){
			int num;
			cin >> num;
			if(idx == -1 && num > 0){
				idx = i;
			}
			a[i] = num;
		}
		if(idx == -1){
			for(int i = 0; i < n; i++){
				cout << a[i] << " ";
			}
			cout << "\n";
			continue;
		}
		while(k--){
			if(idx != n-1){
				a[idx]--;
				if(a[idx] == 0){
					idx++;
				}
				a[n-1]++;
			} else {
				break;
			}
		}
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}