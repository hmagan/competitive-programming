#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> owe(n, 0);
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		owe[a-1] -= c;
		owe[b-1] += c;
	}

	int debt = 0;
	for(int i = 0; i < n; i++){
		if(owe[i] > 0){
			debt += owe[i];
		}
	}

	cout << debt << "\n";
}
