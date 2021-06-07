#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, bool>> a(n);
	vector<pair<int, bool>> b(n);
	vector<pair<int, pair<int, int>>> fastest;
	for(int i = 0; i < n; i++){
		int ai, bi;
		cin >> ai >> bi;
		a[i] = {ai, false};
		b[i] = {bi, false};
		fastest.push_back({ai, {0, i}});
		fastest.push_back({bi, {1, i}});
		if(i < n / 2){
			a[i].second = true;
			b[i].second = true;
		}
	}	

	sort(fastest.begin(), fastest.end());
	for(int i = 0; i < n; i++){
		pair<int, pair<int, int>> part = fastest[i];
		if(part.second.first == 0){
			a[part.second.second].second = true;
		} else {
			b[part.second.second].second = true;
		}
	}

	for(int i = 0; i < n; i++){
		cout << ((a[i].second) ? "1" : "0");
	}
	cout << "\n";
	for(int i = 0; i < n; i++){
		cout << ((b[i].second) ? "1" : "0");
	}
	cout << "\n";
}
