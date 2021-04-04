#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("socdist2.in");
    ofstream fout("socdist2.out");
	
	int n;
	fin >> n;
	
	vector<vector<int>> cows;
	bool healthy = false;
	
	for(int i = 0; i < n; i++){
		int pos, sick;
		fin >> pos >> sick;
		
		if(!healthy && sick == 0){
			healthy = true;
		}
		
		vector<int> temp;
		temp.push_back(pos);
		temp.push_back(sick);
		cows.push_back(temp);
	}
	
	if(!healthy){
		fout << n;
		return 0;
	}
	
	for(int i = 0; i < cows.size(); i++){
		int min = cows[i][0];
		int idx = i;
		for(int j = i+1; j < cows.size(); j++){
			if(cows[j][0] < min){
				min = cows[j][0];
				idx = j;
			}
		}
		if(idx != i){
			swap(cows[i], cows[idx]);
		}
	}
	
	int min_radius = 1337;
	for(int i = 0; i < cows.size()-1; i++){
		if(((cows[i][1] == 0 && cows[i+1][1] == 1) || (cows[i][1] == 1 && cows[i+1][1] == 0)) && cows[i+1][0] - cows[i][0] < min_radius){
			min_radius = cows[i+1][0] - cows[i][0];
		}
	}
	
	int count = 1;
	int last = -1;
	int last_idx = -1;
	for(int i = 0; i < cows.size(); i++){
		if(cows[i][1] == 1){
			last = cows[i][0];
			last_idx = i;
			break;
		}
	}
	
	for(int i = last_idx+1; i < cows.size(); i++){
		if(cows[i][1] == 1){
			if(cows[i][0] - last >= min_radius){
				//cout << cows[i][0] << " & " << last << "\n";
				count++;
			}
			last = cows[i][0];
		}
	}
	
	fout << count;
}