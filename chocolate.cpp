#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int nuts = 0;

	int bar[n];
	for(int i = 0; i < n; i++){
		cin >> bar[i];
		if(bar[i] == 1){
			nuts++;
		}
	}

	if(nuts == 0){
		cout << "0\n";
		return 0;
	}
	if(nuts == 1){
		cout << "1\n";
		return 0;
	}

	vector<int> dist(nuts-1);
	int last = 0;
	int idx = 0;
	bool first = true;
	for(int i = 0; i < n; i++){
		if(first && bar[i] == 1){
			last = i;
			first = false;
			continue;
		}
		if(bar[i] == 1){
			dist[idx] = i - last;
			last = i;
			idx++;
		}
	}

	long long result = dist[0];
	for(int i = 1; i < dist.size(); i++){
		result *= dist[i];
	}

	cout << result << "\n";
}
