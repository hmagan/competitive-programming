#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int k = n;
		vector<int> a(n);
		set<int> contains;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			contains.insert(a[i]);
		}

		sort(a.begin(), a.end());
		vector<int> add;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(contains.find(abs(a[j] - a[i])) == contains.end()){
					add.push_back(a[j] - a[i]);
				}
			}
		}
		
		while(add.size() > 0){
			int num = add[0];
			add.erase(add.begin());
			if(contains.find(num) != contains.end()){
				continue;
			}
			for(int i = 0; i < a.size(); i++){
				if(contains.find(abs(num - a[i])) == contains.end()){
					add.push_back(abs(num - a[i]));
				}
			}
			a.push_back(num);
			contains.insert(num);
			if(a.size() > 300){
				break;
			}
		}

		if(a.size() <= 300){
			cout << "YES\n" << a.size() << "\n";
			for(int i = 0; i < a.size(); i++){
				cout << a[i] << " ";
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}	
}
