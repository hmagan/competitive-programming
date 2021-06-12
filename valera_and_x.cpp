#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<char>> paper(n, vector<char>(n));
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < n; j++){
			paper[i][j] = str[j];
		}
	}	
	char x = paper[0][0];
	char other = paper[0][1];

	set<pair<int, int>> bad;
	bool good = true;
	for(int i = 0; i < n; i++){
		bad.insert({i, i});
		if(paper[i][i] != x){
			good = false;
			break;
		}
	}
	int idx = n-1;
	for(int i = 0; i < n; i++){
		bad.insert({idx, i});
		if(paper[idx][i] != x){
			good = false;
			break;
		}
		idx--;
	}

	if(good){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(bad.find({i, j}) == bad.end() && paper[i][j] != other){
					good = false;
					break;
				}
			}
			if(!good){
				break;
			}
		}
	}

	cout << ((good && x != other) ? "YES\n" : "NO\n");
}
