#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;

	vector<pair<int, int>> generals; 

	for(int i = min(xa, xb); i <= max(xa, xb); i++){
		generals.push_back({i, min(ya, yb)});
		generals.push_back({i, max(ya, yb)});
		if(i == min(xa, xb) || i == max(xa, xb)){
			for(int j = min(ya, yb) + 1; j < max(ya, yb); j++){
				generals.push_back({i, j});
			}
		}
	}
	
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int x, y, r;
		cin >> x >> y >> r;
		for(int j = 0; j < generals.size(); j++){
			if(((double) sqrt(pow(generals[j].first - x, 2.0) + pow(generals[j].second - y, 2.0))) <= r){
				generals.erase(generals.begin() + j);
				j--;
			}
		}
	}

	cout << generals.size() << "\n";
}
