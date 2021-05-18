#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        long long num;
        long long k;
        cin >> num >> k;
        string a = to_string(num);
        while(k > 1){
            vector<int> digits;
            int mi = 10;
            int ma = -1;
            for(int i = 0; i < a.length(); i++){
                digits.push_back(a[i] - '0');
                if(digits[i] < mi){
                    mi = digits[i];
                }
                if(digits[i] > ma){
                    ma = digits[i];
                }
            }
            k--;
            num = num + mi * ma;
            a = to_string(num);
            if(mi == 0 || ma == 0){
                break;
            }
        }
        cout << a << "\n";
    }

    return 0;
}
