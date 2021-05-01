#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        long long r, b, d;
        cin >> r >> b >> d;
        long long mi = min(r, b);
        long long ma = max(r, b);
        if(ma <= mi * (d+1)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}