#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, temp;
	
	int odds = 0;
	int evens = 0;
	
	cin >> n;
	int nums[n];
	for(int i = 0; i < n; i++){
		cin >> temp;
		
		if(temp % 2 == 0){
			evens++;
		} else {
			odds++;
		}
		
		nums[i] = temp;
	}
	
	int j = 0;
	while(true){
		if(j % 2 == 0){
			if(evens >= 1){
				j++;
				evens--;
			} else {
				if(odds >= 2){
					j++;
					odds -= 2;
				} else {
					if(odds == 1){
						j--;
					}
					break;
				}
			}
		} else {
			if(odds >= 1){
				j++;
				odds--;
			} else {
				break;
			}
		}
	}
	
	cout << j;
}