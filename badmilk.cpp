#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("badmilk.in");
	ofstream fout ("badmilk.out");
	
	int n, m, d, s;
	
	fin >> n >> m >> d >> s;
	
	
	int party[d][3];
	for(int i = 0; i < d; i++){
		fin >> party[i][0] >> party[i][1] >> party[i][2];
	}
	for(int i = 0; i < d; i++){
		int min = party[i][2];
		int idx = i;
		for(int j = i + 1; j < d; j++){
			if(party[j][2] < min){
				min = party[j][2];
				idx = j;
			}
		}
		if(idx != i){
			swap(party[i], party[idx]);
		}
	}
	int sick[s][2];
	for(int i = 0; i < s; i++){
		fin >> sick[i][0] >> sick[i][1];
	}
	for(int i = 0; i < s; i++){
		int min = sick[i][1];
		int idx = i;
		for(int j = i + 1; j < s; j++){
			if(sick[j][1] < min){
				min = sick[j][1];
				idx = j;
			}
		}
		if(idx != i){
			swap(sick[i], sick[idx]);
		}
	}
	int max = s;
	for(int i = 1; i <= m; i++){
		vector<int> drank;
		set<int> people;
		vector<int> times;
		for(int j = 0; j < d; j++){
			if(party[j][1] == i){
				drank.push_back(party[j][0]);
				people.insert(party[j][0]);
				times.push_back(party[j][2]);
			}
		}
		bool good = true;
		for(int j = 0; j < s; j++){
			bool contained = false;
			for(int k = 0; k < drank.size(); k++){
				if(times[k] >= sick[j][1]){ // >= saves the day fyi
					continue;
				}
				if(drank[k] == sick[j][0]){
					contained = true;
					break;
				}
			}
			if(!contained){
				good = false;
				break;
			}
		}
		if(good && people.size() > max){
			max = people.size();
		}
	}
	fout << max;
}