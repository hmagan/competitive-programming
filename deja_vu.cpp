#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s){
    return (s == string(s.rbegin(), s.rend()));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        bool only_a = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != 'a'){
                only_a = false;
                break;
            }
        }

        if(only_a){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            string temp = s + "a";
            if(is_palindrome(temp)){
                temp = "a" + s;
            }
            cout << temp << "\n";
        }
    }
}