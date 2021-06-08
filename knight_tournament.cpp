#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<int> alive;
	for(int i = 0; i < n; i++){
		alive.insert(i);
	}

	vector<int> ans(n, 0);
	for(int i = 0; i < m; i++){
		int l, r, x;
		cin >> l >> r >> x;
		l--; r--; x--;
		auto it = alive.lower_bound(l);
		vector<set<int>::iterator> dead;
		while(it != alive.end()){
			int knight = *it;
			if(knight <= r && knight != x){
				ans[knight] = x + 1;
				dead.push_back(it);
			} else if(knight > r){
				break;
			}
			it++;
		}
		for(int i = 0; i < dead.size(); i++){
			auto iter = dead[i];
			alive.erase(iter);
		}
	}

	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}
