#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	set<int> seen;
	vector<int> x;
	vector<vector<int>> past(1e6, vector<int>(2, -1));

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(seen.find(a) != seen.end()){
			if(past[a][1] > -1){
				if(i - past[a][0] != past[a][1]){
					past[a][1] = -1;
					for(int j = 0; j < x.size(); j++){
						if(x[j] == a){
							x.erase(x.begin() + j);
							break;
						}
					}
				} else {
					past[a][0] = i;
				}
			} else {
				past[a][1] = i - past[a][0];
				past[a][0] = i;
			}
		} else {
			seen.insert(a);
			x.push_back(a);
			past[a][0] = i;
		}
	}

	cout << x.size() << "\n";
	sort(x.begin(), x.end());
	for(int i = 0; i < x.size(); i++){
		if(past[x[i]][1] == -1){
			past[x[i]][1]++;
		}
		cout << x[i] << " " << past[x[i]][1] << "\n";
	}
}
