#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n, p;
		cin >> n >> p;

		int edges = 2 * n + p;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				cout << i << " " << j << "\n";
				edges--;
				if(edges == 0){
					break;
				}
			}
			if(edges == 0){
				break;
			}
		}

		cout << "\n";
	}	
}
