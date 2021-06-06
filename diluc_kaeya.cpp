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

		string s;
		cin >> s;

		vector<long long> ans(n);
		int d = 0;
		int k = 0;

		map<double, int> ratios;

		for(int i = 0; i < n; i++){
			if(s[i] == 'D'){
				d++;
			} else {
				k++;
			}
			double ratio = (double) d / k;
			if(ratios.find(ratio) == ratios.end()){
				ratios.insert({ratio, 1});
			} else {
				ratios[ratio]++;
			}
			ans[i] = ratios[ratio];
			cout << ans[i] << " ";
		}
		cout << "\n";	

	}
}
