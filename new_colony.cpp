#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        int h[n];
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }

        int ans = -1;
        for(int i = 0; i < k; i++){
            int idx = -2;
            for(int j = 0; j < n-1; j++){
                if(h[j+1] > h[j]){
                    idx = j;
                    break;
                }
            }
            ans = idx + 1;
            if(idx == -2){
                break;
            }
            h[idx]++;
        }
        cout << ans << "\n";
    }
}
