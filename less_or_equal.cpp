#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int nums[n];
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	
	int x = sizeof(nums) / sizeof(nums[0]);
	sort(nums, nums + x);
	
	int threshold = nums[k-1];
	
	if(k == 0){
		if(nums[0] == 1){
			cout << -1;
		} else {
			cout << 1;
		}
	} else {
		if(nums[k] != threshold){
			cout << nums[k-1];
		} else {
			cout << -1;
		}
	}
	
	return 0;
}