#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> a;
    long long health = 0;
    long long potions = 0;
    vector<long long> hp(n);
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        if(x >= 0){
            health += x;
            potions++;
        } else {
            a.push_back({x, i});
        }
        hp[i] = health;
    }
    sort(a.rbegin(), a.rend());
    
    int idx = 0;
    while(idx < a.size()){
        bool good = true;
        for(int i = a[idx].second; i < n; i++){
            if(hp[i] + a[idx].first < 0){
                good = false;
                break;
            }
        }
        if(good){
            for(int i = a[idx].second; i < n; i++){
                hp[i] += a[idx].first;
            }
            potions++;
        }
        idx++;
    }

    cout << potions << "\n";
}
