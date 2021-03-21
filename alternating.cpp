#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	long long totals[t];
	
	for(int p = 0; p < t; p++){
		int n;
		cin >> n;
		
		int nums[n];
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		
		bool pos = nums[0] > 0;
		int max = 1;
		int low = 1;
		long long sum = nums[0];
		for(int i = 1; i < n; i++){
			if(nums[i] > 0 == pos){
				low++;
				if(nums[i] > sum){
					sum = nums[i];
				}
			} else {
				break;
			}
		}
		
		//a lot of repeated code, whoops
		for(int i = low; i < n; i++){
			if(pos){
				pos = false;
				bool change = false;
				for(int j = low; j < n; j++){
					if(nums[j] < 0){
						low = j + 1;
						max++;
						change = true;
						int maxi = nums[j];
						int idx = j;
						for(int k = j; k < n; k++){
							if(nums[k] > 0){
								break;
							} else {
								if(nums[k] > maxi){
									maxi = nums[k];
									idx = k;
								}
							}
						}
						sum += maxi;
						low = idx + 1;
						i = low - 1;
						break;
					}
				}
				if(!change){
					break;
				}
			} else {
				pos = true;
				bool change = false;
				for(int j = low; j < n; j++){
					if(nums[j] > 0){
						low = j + 1;
						max++;
						change = true;
						int maxi = nums[j];
						int idx = j;
						for(int k = j; k < n; k++){
							if(nums[k] < 0){
								break;
							} else {
								if(nums[k] > maxi){
									maxi = nums[k];
									idx = k;
								}
							}
						}
						sum += maxi;
						low = idx + 1;
						i = low - 1;
						break;
					}
				}
				if(!change){
					break;
				}
			}
		}
		totals[p] = sum;
	}
	for(long long i : totals){
		cout << i << "\n";
	}
}