#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;
        long long sr = sqrt(n/2);
        long long sr2 = sqrt(n/4);
        //cout << "n/2 (Sqrt) == " << sr << "\n"; 
        cout << (n != 1 && (((n & (n-1)) == 0) || (n % 2 == 0 && (sr * sr == (n/2))) || (n % 4 == 0 && (sr2 * sr2 == (n/4)))) ? "YES\n" : "NO\n");
    }
}
