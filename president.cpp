#include <bits/stdc++.h>

using namespace std;

int n, m;

bool is_valid(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char c;
	cin >> n >> m >> c;

	int room[n][m];
	vector<pair<int, int>> pres;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			room[i][j] = s[j];
			if(s[j] == c){
				pres.push_back({i, j});
			}
		}
	}	

	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	set<char> deputies;

	for(int i = 0; i < pres.size(); i++){
		for(int j = 0; j < 4; j++){
			if(is_valid(pres[i].first + dx[j], pres[i].second + dy[j]) && room[pres[i].first + dx[j]][pres[i].second + dy[j]] != '.' && room[pres[i].first + dx[j]][pres[i].second + dy[j]] != c){
				deputies.insert(room[pres[i].first + dx[j]][pres[i].second + dy[j]]);
			}
		}
	}

	cout << deputies.size() << "\n";
}
