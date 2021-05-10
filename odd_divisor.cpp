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

        if(n % 2 == 0){
            while(n % 2 == 0 && n / 2 != 1 && n != 3 && n!= 5 && n != 7){
                n /= 2;
            }
        }
        //cout << n << "\n";
        cout << ((n % 2 == 1) ? "YES" : "NO") << "\n";;
    }
}