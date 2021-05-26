#include <bits/stdc++.h>

using namespace std;

bool sort_second(vector<int> &p1, vector<int> &p2){
    return (p2[1] < p1[1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> visitors(n);
    for(int i = 0; i < n; i++){
        int c, p;
        cin >> c >> p;
        visitors[i] = {c, p, i+1};
    }

    int k;
    cin >> k;

    vector<pair<int, int>> tables(k);
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        tables[i] = {x, i+1};
    }

    sort(tables.begin(), tables.end());
    sort(visitors.begin(), visitors.end(), sort_second);
    
    int num = 0;
    int total = 0;

    vector<pair<int, int>> ans;
    for(int i = 0; i < tables.size(); i++){
        for(int j = 0; j < visitors.size(); j++){
            if(visitors[j][0] <= tables[i].first){
                ans.push_back({visitors[j][2], tables[i].second});
                total += visitors[j][1];
                num++;
                visitors.erase(visitors.begin() + j);
                break;
            }
        }
    }

    cout << num << " " << total << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}
