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

        if(n % 2050){
            cout << -1 << "\n";
        } else {
            int count = 0;
            n /= 2050;
            int digit = 0;
            while(n > 0){
                digit = n % 10;
                count += digit;
                n /= 10;
            }
            cout << count << "\n";
        }
    }
}
