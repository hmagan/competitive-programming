#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int k = floor(sqrt(x));
        int curr = (k * (k + 1)) / 2;

        while(curr < x){
            k++;
            curr += k;
        }

        if(curr - x == 1){
            cout << k + 1 << "\n";
        } else {
            cout << k << "\n";
        }
    }
}