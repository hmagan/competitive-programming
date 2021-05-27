#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    string a;
    cin >> a;

    vector<vector<int>> translate = {{2}, {3}, {3, 2, 2}, {5}, {5, 3}, {7}, {7, 2, 2, 2}, {7, 3, 3, 2}};

    vector<int> nums;
    for(int i = 0; i < a.length(); i++){
        int x = a[i] - '0';
        if(x > 1){
            int idx = x - 2;
            for(int j = 0; j < translate[idx].size(); j++){
                nums.push_back(translate[idx][j]);
            }
        }
    }

    sort(nums.rbegin(), nums.rend());
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i];
    }
    cout << "\n";
}
