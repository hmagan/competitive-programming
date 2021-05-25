#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> pairs;

bool contains_bear(int i, int j){
    for(int k = 0; k < pairs.size(); k++){
        if(i <= pairs[k].first && j >= pairs[k].second){
            return true;
        }   
    }
    return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    string s;
    cin >> s;

    if(s.length() < 4){
        cout << "0\n";
        return 0;
    }

    int count = 0;
    for(int i = 0; i < s.length() - 3; i++){
        if(s.substr(i, 4) == "bear"){
            pairs.push_back({i, i + 3});
        }
    }
    for(int i = 0; i < s.length(); i++){
        for(int j = i + 3; j < s.length(); j++){
            if(contains_bear(i, j)){
                count += (s.length() - j);
                break; 
            }
        }
    }

    cout << count << "\n";
}