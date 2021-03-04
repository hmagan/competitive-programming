#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("measurement.in");
	ofstream fout ("measurement.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	fin >> n;
	
	int nums[n][2];
	string names[n];
	
	//Bessie, Elsie, Mildred
	int counts[3];
	for(int i = 0; i < 3; i++){
		counts[i] = 7;
	}
	
	for(int i = 0; i < n; i++){
		fin >> nums[i][0] >> names[i];
		int t;
		fin >> t;
		nums[i][1] = t;
	}
	
	for(int i = 0; i < n; i++){
		int minimum = nums[i][0];
		int idx = i;
		for(int j = i + 1; j < n; j++){
			if(nums[j][0] < minimum){
				minimum = nums[j][0];
				idx = j;
			}
		}
		if(idx != i){
			int temp = minimum;
			nums[idx][0] = nums[i][0];
			nums[i][0] = temp;
			temp = nums[idx][1];
			nums[idx][1] = nums[i][1];
			nums[i][1] = temp;
			string t = names[idx];
			names[idx] = names[i];
			names[i] = t;
		}
	}
	
	int count = 0;
	
	bool leaders[3];
	for(int i = 0; i < 3; i++){
		leaders[i] = true;
	}
	
	int top = 7;
	
	for(int i = 0; i < n; i++){
		int idx;
		if(names[i] == "Bessie"){
			idx = 0;
		} else if(names[i] == "Elsie"){
			idx = 1;
		} else if (names[i] == "Mildred"){
			idx = 2;
		}
		counts[idx] += nums[i][1];
		int n_top = -1;
		bool good[3];
		for(int j = 0; j < 3; j++){
			if(counts[j] >= n_top){
				n_top = counts[j];
			}
		}
		top = n_top;
		for(int j = 0; j < 3; j++){
			good[j] = counts[j] >= top;
		}
		bool display = false;
		for(int j = 0; j < 3; j++){
			if(good[j] != leaders[j]){
				display = true;
			}
			leaders[j] = good[j];
		}
		if(display){
			count++;
		}
	}
	
	fout << count;

	return 0;
}