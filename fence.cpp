#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	long long h[n];
	long long s[n];
	for(int i = 0; i < n; i++){
		cin >> h[i];
		s[i] = ((i == 0) ? h[i] : h[i] + s[i-1]);
	}

	long long mi = INT_MAX;
	long long idx = -1;
	for(int i = 0; i < n - k + 1; i++){
		long long sub;
		if(i == 0){
			sub = 0;
		} else {
			sub = s[i-1];
		}
		long long sum = s[i+k-1]-sub;
		if(sum < mi){
			mi = sum;
			idx = i;
		}
	}

	cout << idx + 1 << "\n";
}
