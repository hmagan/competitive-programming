#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<char> ans(n, ' ');
    while(s.length() > 0){
        int idx = s.length() / 2;
        if(s.length() % 2 == 0){
            idx--;
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(ans[i] == ' '){
                count++;
            }
            if(count == idx+1){
                ans[i] = s[0];
                break;
            }
        }
        s = s.substr(1);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i];
    }
    cout << "\n";
}