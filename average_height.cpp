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

        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<long long> ans;
        for(int i = 0; i < a.size(); i++){
            if(a[i] % 2 == 0){
                ans.push_back(a[i]);
                a.erase(a.begin() + i);
                i--;
            }
        }
        for(int i = 0; i < a.size(); i++){
            ans.push_back(a[i]);
        }
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}