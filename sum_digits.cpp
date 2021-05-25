#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    string s;
    cin >> s;

    int digits = s.length();
    int turns = 0;
    while(digits > 1){
        int n = 0;
        for(int i = 0; i < digits; i++){
            n += s[i] - '0';
        }
        s = to_string(n);
        digits = s.length();
        turns++;
    }

    cout << turns << "\n";
}