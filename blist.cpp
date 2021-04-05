#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("blist.in");
    ofstream cout("blist.out");
	
	int n;
	cin >> n;
	
	bool in_use[1000];
	
	int list[n][3];
	for(int i = 0; i < n; i++){
		cin >> list[i][0] >> list[i][1] >> list[i][2];
	}
	
	for(int i = 0; i < n; i++){
		int idx = i;
		int min = list[i][0];
		for(int j = i+1; j < n; j++){
			if(list[j][0] < min){
				min = list[j][0];
				idx = j;
			}
		}
		if(idx != i){
			swap(list[i], list[idx]);
		}
	}
	
	vector<vector<int>> milking;
	int curr = 0;
	int total = 0;
	int max = -1;
	for(int t = 0; t < 1000; t++){
		if(list[curr][0] == t){
			vector<int> temp;
			temp.push_back(list[curr][1]);
			int count = 0;
			for(int i = 0; i < 1000; i++){
				if(!in_use[i]){
					in_use[i] = true;
					temp.push_back(i);
					total++;
					count++;
				}
				if(count == list[curr][2]){
					break;
				}
			}
			curr++;
			milking.push_back(temp);
			if(curr == n){
				curr = 0;
			}
		}
		for(int i = 0; i < milking.size(); i++){
			if(milking[i][0] == t){
				for(int j = 1; j < milking[i].size(); j++){
					in_use[milking[i][j]] = false;
					total--;
				}
				milking.erase(milking.begin()+i);
				break;
			}
		}
		if(total > max){
			max = total;
		}
	}
	
	cout << max;
}