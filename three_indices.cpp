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
		int pee[n];
		for(int i = 0; i < n; i++){
			cin >> pee[i];
		}
		int ans[3];
		bool good = false;
		for(int i = 1; i < n - 1; i++){
			int a, b, c;
			a = -1;
			c = -1;
			b = i;
			for(int j = i + 1; j < n; j++){
				if(pee[j] < pee[i]){
					c = j;
					break;
				}
			}
			for(int j = i - 1; j >= 0; j--){
				if(pee[j] < pee[i]){
					a = j;
					break;
				}
			}
			if(a != -1 && c != -1){
				ans[0] = a+1;
				ans[1] = b+1;
				ans[2] = c+1;
				good = true;
				break;
			}
		}


		if(good){
			cout << "YES\n";
			for(int i = 0; i < 3; i++){
				cout << ans[i] << " ";
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
}