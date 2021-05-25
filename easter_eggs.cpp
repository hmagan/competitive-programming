#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    string rainbow = "ROYGBIV";
    string gbiv = "GBIV";
    int n;
    cin >> n;

    int idx = 0;
    string curr = "";
    for(int i = 0; i < n && i < 3; i++){
        curr += rainbow[idx];
        idx++;
        n--;
    }
    idx = 0;
    while(n--){
        curr += gbiv[idx];
        idx++;
        idx %= 4;
    }

    cout << curr << "\n";
}