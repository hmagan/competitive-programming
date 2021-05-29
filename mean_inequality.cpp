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

        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        vector<int> big;
        vector<int> small;

        bool bigg = false;
        while(a.size() > 0){
            if(bigg){
                big.push_back(a[a.size()-1]);
                a.erase(a.begin()+a.size()-1);
                bigg = false;
            } else {
                small.push_back(a[0]);
                a.erase(a.begin());
                bigg = true;
            }
        }

        for(int i = 0; i < big.size(); i++){
            cout << small[i] << " " << big[i] << " ";
        }

        //redundant af
        if(n * 2 % 2 == 1){
            cout << small[n];
        }

        cout << "\n";
    }
}
