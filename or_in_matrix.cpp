#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<pair<int, int>> loc;
	vector<bool> x(m);
	vector<bool> y(n);
	int b[m][n];
	for(int i = 0; i < m; i++){
		bool check = true;
		for(int j = 0; j < n; j++){
			cin >> b[i][j];
			if(b[i][j] == 1){
				loc.push_back({i, j});
			} else {
				check = false;
			}
		}
		x[i] = check;
	}	

	for(int i = 0; i < n; i++){
		bool check = true;
		for(int j = 0; j < m; j++){
			if(b[j][i] != 1){
				check = false;
				break;
			}
		}
		y[i] = check;
	}

	bool good = true;
	set<pair<int, int>> ans;
	for(int i = 0; i < loc.size(); i++){
		if(!(x[loc[i].first] || y[loc[i].second])){
			good = false;
			break;
		} else {
			if(x[loc[i].first] && y[loc[i].second]){
				ans.insert(loc[i]);
			}
		}
	}

	if(!good || (ans.size() == 0 && loc.size() > 0)){
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(ans.find({i, j}) != ans.end()){
					cout << "1 ";
				} else {
					cout << "0 ";
				}
			}
			cout << "\n";
		}
	}
}
