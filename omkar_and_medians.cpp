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

		int b[n];
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}

		set<int> s;
		bool good = true;

		s.insert(b[0]);
		for(int i = 1; i < n; i++){
			int prev = b[i-1];
			if(prev < b[i]){
				auto it = s.upper_bound(prev);
				if(it != s.end() && *it < b[i]){
					good = false;
					break;
				}
			}
			if(prev > b[i]){
				auto it = s.lower_bound(prev);
				if(it != s.begin() && *(--it) > b[i]){
					good = false;
					break;
				}
			}
			s.insert(b[i]);
		}

		if(good){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}	
}
