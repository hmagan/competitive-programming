#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int n, k;
    cin >> n >> k;

    int idx = 0;
    string ans = "";

    while(n--){
        ans += alphabet[idx];
        idx++;
        idx %= k;
    }

    cout << ans << "\n";
}
