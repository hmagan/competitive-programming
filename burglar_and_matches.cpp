#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<int, int> matchboxes[m];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        matchboxes[i] = {b, a};
    }
    sort(matchboxes, matchboxes + m);

    int count = 0;
    int idx = m-1;
    while(idx >= 0 && n > 0){
        if(n - matchboxes[idx].second >= 0){
            count += (matchboxes[idx].first * matchboxes[idx].second);
            n -= matchboxes[idx].second;
        } else {
            count += (n * matchboxes[idx].first);
            n = 0;
        }
        idx--;
    }
    cout << count << "\n";
}