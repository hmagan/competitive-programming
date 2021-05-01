#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        //    x    y
        pair<int, int> counts = {n - 1, m - 1};
        if(counts.first + counts.second * (counts.first+1) == k || counts.second + counts.first * (counts.second+1) == k){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
