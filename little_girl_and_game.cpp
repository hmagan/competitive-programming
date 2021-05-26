#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    string s;
    cin >> s;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector<pair<char, int>> letters(26);
    for(int i = 0; i < 26; i++){
        letters[i] = {alphabet[i], 0};
    }

    for(int i = 0; i < s.length(); i++){
        int idx = s[i] - 'a';
        letters[idx].second++;
    }

    int odd = 0;
    int even = 0;
    for(int i = 0; i < letters.size(); i++){
        if(letters[i].second > 0){
            if(letters[i].second % 2 == 0){
                even++;
            } else {
                odd++;
            }
        }
    }

    if(odd <= 1){
        cout << "First\n";
    } else {
        if(odd % 2 == 0){
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    } 
}
