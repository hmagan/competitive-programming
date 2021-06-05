#include <bits/stdc++.h>

using namespace std;

int n, m, k, t;

bool by_location(const pair<int, int> &p1, const pair<int, int> &p2){
	return (p1.first * m + p1.second < p2.first * m + p2.second);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> t;

	vector<pair<int, int>> waste;
	set<pair<int, int>> s;
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		s.insert({a, b});
		waste.push_back({a, b});
	}

	sort(waste.begin(), waste.end(), by_location);

	string c[] = {"Carrots\n", "Kiwis\n", "Grapes\n"};
	while(t--){
		int i, j;
		cin >> i >> j;
		i--; j--;
		if(s.find({i, j}) != s.end()){
			cout << "Waste\n";
		} else {
			int idx = i * m + j;
			int add = 0;
			for(int i = 0; i < k; i++){
				if(waste[i].first * m + waste[i].second > idx){
					break;
				}
				add = i + 1;
			}	
			idx -= add;
			idx %= 3;
			cout << c[idx];
		}
	}
}
