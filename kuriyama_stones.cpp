#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> v(n);
	vector<long long> s(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		s[i] += ((i == 0) ? v[i] : v[i] + s[i-1]);
	}	
	
	vector<long long> u = v;
	sort(u.begin(), u.end());
	vector<long long> su(n);
	for(int i = 0; i < n; i++){
		su[i] += ((i == 0) ? u[i] : u[i] + su[i-1]);
	}	

	int m;
	cin >> m;
	while(m--){
		int type, l, r;
		cin >> type >> l >> r;
		l -= 2; r--;
		long long val1 = -1, val2 = -1;
		if(l < 0){
			val1 = 0;
		}
		if(type == 1){
			if(val1 != 0){
				val1 = s[l];
			}	
			val2 = s[r];
		} else {
			if(val1 != 0){
				val1 = su[l];
			}
			val2 = su[r];
		}
		cout << val2 - val1 << "\n";
	}
}
