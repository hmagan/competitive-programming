#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n];
    int inc = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        inc += a[i];
    }
    sort(a, a + n);
    int idx = 0;
    bool damage_control = false;
    if(a[idx] > 0){
        damage_control = true;
    }
    while(k--){
        a[idx] *= -1;
        inc += (2 * a[idx]);
        if(!damage_control){
            if(idx < n-1 && a[idx+1] < 0){
                idx++;
            } else {
                damage_control = true;
                sort(a, a + n);
                idx = 0;
            }
        }
    }
    cout << inc << "\n";
}