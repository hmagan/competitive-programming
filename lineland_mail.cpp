#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long cities[n];
	for(int i = 0; i < n; i++){
		cin >> cities[i];
	}	

	for(int i = 0; i < n; i++){
		if(i == 0){
			cout << cities[1] - cities[i] << " ";
		} else if(i == n-1){
			cout << cities[i] - cities[i-1] << " ";
		} else {
			cout << min(cities[i+1] - cities[i], cities[i] - cities[i-1]) << " "; 
		}

		long long furthest = max(cities[n-1] - cities[i], cities[i] - cities[0]);
		cout << furthest << "\n";
	}
}
