#include <bits/stdc++.h>

using namespace std;

double get_dist(int x, int y, int i, int j){
	return sqrt(pow(y - j, 2.0) + pow(x - i, 2.0));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;	

	set<char> keys;
	vector<pair<pair<int, int>, char>> reg;
	vector<pair<int ,int>> shifts;
	for(int i = 0; i < n; i++){
		string row;
		cin >> row;
		for(int j = 0; j < m; j++){
			char letter = row[j];
			if(letter == 'S'){
				shifts.push_back({i, j});
			} else {
				reg.push_back({{i, j}, letter});
				keys.insert(letter);
			}
		}
	}

	for(int i = 0; i < shifts.size(); i++){
		for(int j = 0; j < reg.size(); j++){
			if(get_dist(shifts[i].first, shifts[i].second, reg[j].first.first, reg[j].first.second) <= x){
				int num = (int) reg[j].second;
				num -= 32;
				char letter = (char) num;
				keys.insert(letter);
			}
		}
	}

	int q;
	cin >> q;

	string s;
	cin >> s;

	int count = 0;
	for(int i = 0; i < q; i++){
		char letter = s[i];
		int num = (int) letter;
		num += 32;
		char new_letter = char(num);
		if(keys.find(letter) != keys.end()){
			continue;
		} else if(keys.find(new_letter) != keys.end() && shifts.size() > 0){
			count++;
		} else {
			count = -1;
			break;
		}
	}

	cout << count << "\n";
}
