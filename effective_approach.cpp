#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    long long v = 0, p = 0;
    int n;
    cin >> n;

    int a[n];
    int ans[n + 1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans[a[i]] = i;
    }

    int m;
    cin >> m;

    while(m--){
        int q;
        cin >> q;
        int idx = ans[q];
        v += idx + 1;
        p += (n - idx);
    }

    cout << v << " " << p << "\n";
}