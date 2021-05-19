#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int gcd = -1;
        for(int i = k; i >= 1; i--){
            if(100 % i == 0 && k % i == 0){
                gcd = i;
                break;
            }
        }
        cout << 100 / gcd << "\n";
    }
}