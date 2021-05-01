#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x;
                cin >> x;
                a.push_back({x, i});
            }
        }
        sort(a.begin(), a.end());

        vector<pair<int, int>> ans;
        for(int i = 0; i < m; i++){
            ans.push_back(a[0]);
            a.erase(a.begin());
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ans[j].second == i){
                    cout << ans[j].first << " ";
                    ans[j].second = -1;
                } else {
                    for(int k = 0; k < a.size(); k++){
                        if(a[k].second == i){
                            cout << a[k].first << " ";
                            a[k].second = -1;
                            break;
                        }
                    }
                }
            }
            cout << "\n";
        }
    }
}
