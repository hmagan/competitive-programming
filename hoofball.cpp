#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("hoofball.in");
    ofstream cout("hoofball.out");
	
	int n;
	cin >> n;
	
	int cows[n];
	for(int i = 0; i < n; i++){
		cin >> cows[i];
	}
	
	bool balls[n][n];
	
	sort(cows, cows + sizeof(cows)/sizeof(cows[0]));
	
	for(int i = 0; i < n; i++){
		bool touched[n] = {false};
		int last = -1;
		int idx = i;
		touched[i] = true;
		while(true){
			if(idx == 0){
				idx++;
				if(last == idx){
					break;
				} else {
					last = idx-1;
				}
				touched[idx] = true;
			} else if(idx == n-1){
				idx--;
				if(last == idx){
					break;
				} else {
					last = idx+1;
				}
				touched[idx] = true;
			} else {
				if(cows[idx] - cows[idx-1] == cows[idx+1] - cows[idx] || cows[idx] - cows[idx-1] < cows[idx+1] - cows[idx]){
					idx--;
					if(last == idx){
						break;
					} else {
						last = idx+1;
					}
					touched[idx] = true;
				} else {
					idx++;
					if(last == idx){
						break;
					} else {
						last = idx-1;
					}
					touched[idx] = true;
				}
			}
		}
		for(int j = 0; j < n; j++){
			balls[i][j] = touched[j];
		}
	}
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << balls[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	int count = 1;
	int biggest = -1;
	int idx_b = -1;
	int values[n];
	for(int i = 0; i < n; i++){
		int c = 0;
		for(int j = 0; j < n; j++){
			if(balls[i][j]){
				c++;
			}
		}
		values[i] = c;
		if(c > biggest){
			biggest = c;
			idx_b = i;
		}
	}
	vector<int> in_use;
	in_use.push_back(idx_b);
	for(int i = 0; i < n; i++){
		if(!balls[idx_b][i]){
			bool good = false;
			for(int j = 0; j < in_use.size(); j++){
				if(balls[in_use[j]][i]){
					good = true;
					break;
				}
			}
			vector<int> possible;
			if(!good){
				for(int j = 0; j < n; j++){
					if(balls[j][i]){
						possible.push_back(j);
					}
				}
				if(possible.size() == 0){
					cout << n;
					return 0;
				} else {
					int maxi = -1;
					int idx = -1;
					for(int j = 0; j < possible.size(); j++){
						if(values[possible[j]] > maxi){
							maxi = values[possible[j]];
							idx = possible[j];
						}
					}
					in_use.push_back(idx);
					count++;
				}
			}
		}
	}
	
	cout << count;
}