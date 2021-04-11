#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		if(n%2==0){
			if(n / 2 - 1 < k){
				cout << -1 << "\n";
				continue;
			}
		} else {
			if(n / 2 < k){
				cout << -1 << "\n";
				continue;
			}
		}
		
		int arr[n];
		for(int i = 1; i <= n; i++){
			arr[i-1] = i;
		}
		
		int idx = 1;
		while(k > 0){
			swap(arr[idx], arr[idx+1]);
			k--;
			idx += 2;
		}
		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}