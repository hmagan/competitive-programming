#include <bits/stdc++.h>

using namespace std;

set<int> sieve_of_eratosthenes(int n){
	vector<bool> good(n+1, true);
	good[0] = false;
	good[1] = false;
	for(int p = 2; p * p <= n; p++){
		if(good[p]){
			for(int i = p * p; i <= n; i += p){
				good[i] = false;
			}
		}
	}
	set<int> ans;
	for(int i = 2; i <= n; i++){
		if(good[i]){
			int q = 1;
			while(q <= n / i){
				q *= i;
				ans.insert(q);
			}		
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	set<int> ans = sieve_of_eratosthenes(n);
	cout << ans.size() << "\n";

	for(auto it = ans.begin(); it != ans.end(); it++){
		cout << *it << " ";
	}
	cout << "\n";
}
