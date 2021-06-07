#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> towers(n);
	vector<pair<int, int>> sorted_towers(n);
	for(int i = 0; i < n; i++){
		cin >> towers[i];
		sorted_towers[i] = {towers[i], i + 1};
	}	

	sort(sorted_towers.begin(), sorted_towers.end());
	vector<pair<int, int>> log;
	int last = -1;
	while(k--){
		if(sorted_towers[0].first == sorted_towers[sorted_towers.size()-1].first){
			break;
		}
		sorted_towers[0].first++;
		sorted_towers[sorted_towers.size()-1].first--;
		log.push_back({sorted_towers[sorted_towers.size()-1].second, sorted_towers[0].second});
		sort(sorted_towers.begin(), sorted_towers.end());
		if(abs(sorted_towers[0].first - sorted_towers[sorted_towers.size()-1].first) == last && last == 1){
			log.erase(log.begin() + log.size()-1);
			break;
		} else {
			last = abs(sorted_towers[0].first - sorted_towers[sorted_towers.size()-1].first);
		}
	}

	cout << abs(sorted_towers[0].first - sorted_towers[sorted_towers.size()-1].first) << " " << log.size() << "\n";
	for(int i = 0; i < log.size(); i++){
		cout << log[i].first << " " << log[i].second << "\n";
	}
}
