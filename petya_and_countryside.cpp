#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ma = 0;
    for(int i = 0; i < n; i++){
        int count = 1;
        int behind = i-1;
        int ahead = i+1;
        while((behind >= 0 && a[behind] <= a[behind+1]) || (ahead < n && a[ahead] <= a[ahead-1])){
            if(behind >= 0 && a[behind] <= a[behind+1]){
                count++;
                behind--;
            }
            if(ahead < n && a[ahead] <= a[ahead-1]){
                count++;
                ahead++;
            }
        }
        if(count > ma){
            ma = count;
        }
    }

    cout << ma << "\n";
}