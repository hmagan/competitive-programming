#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int a_total = 0;
    int g_total = 0;

    int n;
    cin >> n;

    string log = "";
    while(n--){
        int a, g;
        cin >> a >> g;

        int a_p = a+a_total;
        int g_p = g+g_total;
        if(abs(a_p - g_total) > 500 && abs(g_p - a_total <= 500)){
            g_total += g;
            log += "G";
        } else if(abs(a_p - g_total) <= 500 && abs(g_p - a_total > 500)){
            a_total += a;
            log += "A";
        } else if(abs(a_p - g_total) < abs(g_p - a_total)){
            a_total += a;
            log += "A";
        } else if(abs(a_p - g_total) > abs(g_p - a_total)){
            g_total += g;
            log += "G";
        } else {
            if(a_p < g_p){
                a_total += a;
                log += "A";
            } else {
                g_total += g;
                log += "G";
            }
        }
    }

    if(abs(a_total - g_total > 500)){
        cout << "-1\n";
    } else {
        cout << log << "\n";
    }
}
