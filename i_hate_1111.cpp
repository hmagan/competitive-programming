#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        long long x;
        cin >> x;

        bool good = x % 11 == 0 || x % 111 == 0;

        while(!good && x >= 111){
            x -= 111;
            good = x % 11 == 0;
        }

        cout << ((good) ? "YES\n" : "NO\n");
    }
}
