#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<vector<long long>> operations(m);
	for(int i = 0; i < m; i++){
		int l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		operations[i] = {l, r, d};
	}

	vector<long long> q(m+1, 0);
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		q[x]++;
		q[y+1]--;
	}

	vector<long long> p(m);
	for(int i = 0; i < m; i++){
		p[i] = ((i == 0) ? q[i] : q[i] + p[i-1]);
	}

	for(int i = 0; i < m; i++){
		operations[i][2] *= p[i];
	}

	vector<long long> ans(n+1, 0);
	for(int i = 0; i < m; i++){
		int l = operations[i][0];
		int r = operations[i][1];
		ans[l] += operations[i][2];
		ans[r+1] -= operations[i][2];
	}

	vector<long long> p_ans(n, 0);
	for(int i = 0; i < n; i++){
		p_ans[i] = ((i == 0) ? ans[i] : p_ans[i-1] + ans[i]);
	}

	for(int i = 0; i < n; i++){
		cout << a[i] + p_ans[i] << " ";
	}
	
	cout << "\n";
}
