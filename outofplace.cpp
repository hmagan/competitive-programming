#include <bits/stdc++.h>

using namespace std;

int main()
{
	//ifstream cin("outofplace.in");
    //ofstream cout("outofplace.out");
	
	int n;
	cin >> n;
	
	int cows[n];
	for(int i = 0; i < n; i++){
		cin >> cows[i];
	}
	
	int bessie = -1;
	for(int i = 1; i < n-1; i++){
		if((cows[i-1] > cows[i] && cows[i] < cows[i+1]) || (cows[i-1] < cows[i] && cows[i] > cows[i+1])){
			bessie = i;
		}
	}
	if(cows[0] > cows[1]){
		bessie = 0;
	} else if(cows[n-1] < cows[n-2]){
		bessie = n-1;
	}
	if(bessie == -1){
		cout << 0;
		return 0;
	}
	
	bool down;
	//cout << "BESS: " << cows[bessie] << " :" << cows[bessie-1] << "\n";
	if(bessie == 0){
		down = false;
	} else {
		down = cows[bessie] < cows[bessie-1];
	}
	
	int swaps = 0;
	if(down){
		for(int i = bessie; i >= 0; i--){
			int idx = i-1;
			int sub = 0;
			for(int j = i-2; j >= 0; j--){
				if(cows[j] == cows[j+1]){
					sub++;
					idx = j;
				} else {
					break;
				}
			}
			//cout << "IDX: " << idx << "\tI: " << i << "\n";
			swap(cows[i], cows[idx]);
			swaps++;
			
			if(idx != i-1){
				i -= sub;
			}
			
			//for(int j = 0; j < n; j++){
			//	cout << cows[j] << " ";
			//}
			//cout << "\n======" << swaps <<"=======\n";
			bool good = true;
			for(int j = 0; j < n-1; j++){
				//cout << cows[j] << " vs " << cows[j+1] << "\n";
				if(cows[j] > cows[j+1]){
					good = false;
					break;
				}
			}
			if(good){
				break;
			}
		}
	} else {
		for(int i = bessie; i < n; i++){
			int idx = i+1;
			int add = 0;
			for(int j = i+2; j < n; j++){
				if(cows[j] == cows[j-1]){
					idx = j;
					add++;
				} else {
					break;
				}
			}
			//cout << "IDX: " << idx << "\n";
			swap(cows[i], cows[idx]);
			swaps++;
			
			if(idx != i+1){
				i += add;
			}
			
			//for(int j = 0; j < n; j++){
			//	cout << cows[j] << " ";
			//}
			//cout << "\n======" << swaps <<"=======\n";
				
			bool good = true;
			for(int j = 0; j < n-1; j++){
				if(cows[j] > cows[j+1]){
					good = false;
					break;
				}
			}
			if(good){
				break;
			}
		}
	}
	
	cout << swaps;
}