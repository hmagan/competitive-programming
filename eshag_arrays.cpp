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
		
		int avg = 0;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			avg += a[i];
		}

		sort(a.begin(), a.end());
		bool again = true;
		while(a.size() > 0 && again){
			again = false;
			int tot = a[a.size()-1];
			double size = 1.0;
			for(int i = 0; i < a.size()-1; i++){
				if((tot + a[i]) / (size + 1.0) < a[a.size()-1]){
					a.erase(a.begin() + a.size() - 1);
					again = true;
					break;
				} else {
					size++;
					tot += a[i];
				}
			}	
		}

		cout << n - a.size() << "\n";
	}
}
