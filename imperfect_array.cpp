#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	bool sq[100000];
	for(int i = 1; i*i <= 100000; i++){
		sq[i*i] = true;
	}
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(!sq[a[i]]){
				flag = false;
				cout << "YES\n";
				break;
			}
		}
		if(flag){
			cout << "NO\n";
		}
	}
}