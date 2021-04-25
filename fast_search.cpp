#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	
	int k;
	cin >> k;
	while(k--){
		int l, r;
		cin >> l >> r;
		
		int left = -1;
		int right = n;
		while(right > left + 1){
			int m = (left + right)/2;
			if(a[m] >= l){
				right = m;
			} else {
				left = m;
			}
		}
		l = right;
		while(l > 0){
			if(a[l] == a[l-1]){
				l--;
			} else {
				break;
			}
		}
		
		left = -1;
		right = n;
		while(right > left + 1){
			int m = (left + right)/2;
			if(a[m] <= r){
				left = m;
			} else {
				right = m;
			}
		}
		r = left;
		while(r < n-1){
			if(a[r] == a[r+1]){
				r++;
			} else {
				break;
			}
		}
		
		//cout << "R: " << r << "  L: " << l << "      ";
		cout << r - l + 1 << " ";
	}
}