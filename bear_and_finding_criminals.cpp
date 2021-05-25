#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, a;
    cin >> n >> a;

    bool t[n];
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    a--;
    int count = 0;
    int curr = 0;
    while(a + curr < n || a - curr >= 0){
        if(curr == 0){
            count += ((t[a]) ? 1 : 0);
        } else if((a - curr >= 0 && t[a-curr]) && ((a + curr < n && t[a+curr]))){
            count+=2;
        } else if((a + curr >= n && a - curr >= 0 && t[a-curr]) || a - curr < 0 && a + curr < n && t[a+curr]){
            count++;
        }
        curr++;
    }
    cout << count << "\n";
}