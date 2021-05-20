#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        bool good = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0){
                if(a[i] < a[i-1]){
                    good = false;
                }
            }
        }

        int k = 0;

        if(!good){
            k++;
            if(!(a[0] == 1 || a[n-1] == n)){
                k++;
                if(a[0] == n && a[n-1] == 1){
                    k++;
                }
            }
        }

        cout << k << "\n";
    }
}