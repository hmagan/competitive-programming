#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		int nums[n];
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		
		int num = -1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j){
					continue;
				}
				
				if(nums[i] == nums[j]){
					num = nums[i];
					break;
				}
			}
			break;
		}
		if(num == -1){
			cout << 1 << "\n";	
		} else {
			for(int i = 0; i < n; i++){
				if(nums[i] != num){
					cout << i+1 << "\n";
					break;
				}
			}
		}
		
	}
	return 0;
}