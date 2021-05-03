#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;

        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        long long sum = 0;
        sort(a, a + n);
        int idx = 0;
        while(sum < x && idx < n){
            sum += a[idx];
            idx++;
        }
        if(sum == x){
            sum -= a[idx-1];
            bool good = false;
            for(int i = idx; i < n; i++){
                if(sum + a[i] != x){
                    good = true;
                    int temp = a[idx-1];
                    a[idx-1] = a[i];
                    a[i] = temp;
                    break;
                }
            }
            if(good){
                cout << "YES\n";
                for(int i = 0; i < n; i++){
                    cout << a[i] << " ";
                }
                cout << "\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
}
