#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    int h[n+1];
    h[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin >> h[i];
    }

    long long diff = 0;
    long long height = 0;
    for(int i = 0; i < n; i++){
        diff += (h[i] - h[i+1]);
        if(diff < height){
            height = diff;
        }
    }

    cout << abs(height) << "\n";
}