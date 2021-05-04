#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, q;
    cin >> n >> q;

    int a[n];
    int ones = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) ones++;
    }

    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            a[x-1] = 1 - a[x-1];
            if(a[x-1] == 1){
                ones++;
            } else {
                ones--;
            }
        } else {
            cout << ((ones >= x) ? 1 : 0) << "\n";
        }
    }
}
