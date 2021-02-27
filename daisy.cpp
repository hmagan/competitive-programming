#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int flowers[n];
	for(int i = 0; i < n; i++){
		cin >> flowers[i];
	}
	
	int average = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int total = 0;
			int num = 0;
			for(int k = i; k <= j; k++){
				total += flowers[k];
				num++;
			}
			if(total % num == 0){
				total /= num;
			} else {
				continue;
			}
			for(int k = i; k <= j; k++){
				if(flowers[k] == total){
					average++;
					break;
				}
			}
		}
	}
	
	cout << average;
	
	return 0;
}