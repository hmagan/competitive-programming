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

        string s;
        cin >> s;
        set<char> seen;
        seen.insert(s[0]);
        bool good = true;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                if(seen.size() > 0 && seen.find(s[i]) != seen.end()){
                    good = false;
                    break;
                } else {
                    seen.insert(s[i]);
                    //cout << "ADDING " << s[i] << "\n";
                }
            }
        }

        cout << ((good) ? "YES\n" : "NO\n");
    }
}
