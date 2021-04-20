#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long double r[n];
	for(int i = 0; i < n; i++){
		long long x, y;
		cin >> x >> y;
		r[i] = sqrt((x*x) + (y*y)); //pythag
	}
	sort(r, r + n);
	
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		long long radius;
		cin >> radius;
		//binary search for the radius
		long long left = 0;
		long long right = n-1;
		while(right - left > 1){
			int mid = (left + right)/2;
			if(r[mid] > radius){
				right = mid - 1;
			} else {
				left = mid;
			}
		}
		int ans = -1;
		if(r[left] <= radius){
			if(r[right] <= radius){
				ans = right;
			} else {
				ans = left;
			}
		}
		cout << ans+1 << "\n";
	}
}