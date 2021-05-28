#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    if(n % 2 == 0){
        cout << "-1\n";
        return 0;
    }

    vector<vector<int>> ans(3, vector<int>(n, -1));

    for(int i = 0; i < n; i++){
       ans[0][i] = i;
    }

    for(int i = 0; i < n; i++){
       ans[1][i] = (i + 1) % n;
    }

    for(int i = 0; i < n; i++){
       ans[2][i] = (ans[0][i] + ans[1][i]) % n;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
