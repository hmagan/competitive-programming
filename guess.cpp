#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("guess.in");
	ofstream fout ("guess.out");
	
	int n, k;
	fin >> n;
	
	vector<vector<string>> characteristics;
	string temp;
	for(int i = 0; i < n; i++){
		vector<string> pusher;
		fin >> temp >> k;
		for(int j = 0; j < k; j++){
			fin >> temp;
			pusher.push_back(temp);
		}
		characteristics.push_back(pusher);
	}
	
	int count;
	int max_c = -1;
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			count = 0;
			for(int k = 0; k < characteristics[i].size(); k++){
				for(int l = 0; l < characteristics[j].size(); l++){
					if(characteristics[i][k] == characteristics[j][l]){
						count++;
					}
				}
			}
			max_c = max(max_c, count);
		}
	}
	
	fout << max_c + 1;
}