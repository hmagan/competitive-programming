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
		int q;
		cin >> q;
		int left = 0;
		int right = n-1;
		bool flag = false;
		while(left <= right){
			int mid = (left + right) / 2;
			if(a[mid] == q){
				flag = true;
				break;
			} else if(a[mid] > q){
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		if(flag){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}