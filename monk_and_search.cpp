#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int q;
	cin >> q;
	while(q--){
		int query, x;
		cin >> query >> x;
		//binary search pretty cool right
		//necessary bc 1 <= n <= 10e5 && 1 <= q <= 3 * 10e5
		int left = 0;
		int right = n-1;
		int idx = -1;
		while(left <= right){
			int mid = (left + right)/2;
			idx = mid;
			if(a[mid] == x){
				break;
			}
			if(a[mid] < x){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		int total = 0;
		if(query == 0){ // >=
			bool good = false;
			if(a[idx] < x){
				bool check = false;
				for(int i = idx; i < n; i++){
					if(a[i] >= x){
						idx = i;
						check = true;
						break;
					}
				}
				if(check){
					total += n - idx;
				}
				//cout << check << " - " << idx << "\n";
			} else {
				for(int i = idx; i >= 0; i--){
					if(a[i] >= x){
						good = true;
						idx = i;
					} else {
						break;
					}
				}
				if(good){
					total += n - idx;
				}
			}
		} else { // >
			bool good = false;
			if(a[idx] == x || a[idx] < x){
				bool check = false;
				for(int i = idx; i < n; i++){
					if(a[i] > x){
						idx = i;
						check = true;
						break;
					}
				}
				if(check){
					total += n - idx;
				}
				//cout << check << " - " << idx << "\n";
			} else {
				for(int i = idx; i >= 0; i--){
					if(a[i] > x){
						good = true;
						idx = i;
					} else {
						break;
					}
				}
				if(good){
					total += n - idx;
				}
			}
		}
		cout << total << "\n";
	}
}