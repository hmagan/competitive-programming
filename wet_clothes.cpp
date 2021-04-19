#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, g;
	cin >> n >> m >> g;
	int t[n];
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	int a[m];
	int clothes[m];
	for(int i = 0; i < m; i++){
		cin >> a[i];
		clothes[i] = a[i];
	}
	int next = 1;
	vector<vector<bool>> days;
	for(int i = t[0]; i <= t[n-1]; i++){
		if(i == t[next]){
			for(int j = 0; j < m; j++){
				clothes[j] = a[j];
			}
			next++;
			if(next == n){
				next = 0;
			}
		}
		vector<bool> temp;
		for(int j = 0; j < m; j++){
			clothes[j]--;
			if(clothes[j] <= 0){
				temp.push_back(true);
			} else {
				temp.push_back(false);
			}
		}
		days.push_back(temp);
	}
	vector<set<int>> goods;
	vector<int> sizes;
	for(int i = 0; i < days.size(); i++){
		set<int> good;
		for(int j = 0; j < days[i].size(); j++){
			if(days[i][j]){
				good.insert(j);
			}
			//cout << days[i][j] << " ";
		}
		goods.push_back(good);
		sizes.push_back(good.size());
		//cout << "\n";
	}
	
	for(int i = 1; i < goods.size(); i++){
		set<int> g = goods[i];
		int s = sizes[i];
		int idx = i;
		while(idx >= 0 && sizes[idx-1] > sizes[idx]){
			sizes[idx] = sizes[idx-1];
			goods[idx] = goods[idx-1];
			idx--;
		}
		goods[idx] = g;
		sizes[idx] = s;
	}
	int total = 0;
	int idx = goods.size()-1;
	set<int> have;
	while(g > 0 && idx > -1){
		for(int i : goods[idx]){
			have.insert(i);
		}
		g--;
		idx--;
	}
	cout << have.size() << "\n";
}