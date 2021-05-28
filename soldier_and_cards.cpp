#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    vector<int> num_seen(n*100, 0);

    int k1;
    int s1 = 0;
    cin >> k1;
    vector<int> card1(k1);
    for(int i = 0; i < k1; i++){
        cin >> card1[i];
        s1 += card1[i];
    }

    int k2;
    int s2 = 0;
    cin >> k2;
    vector<int> card2(k2);
    for(int i = 0; i < k2; i++){
        cin >> card2[i];
        s2 += card2[i];
    }
    num_seen[s1 * s2]++;
    int fights = 0;
    while(card1.size() > 0 && card2.size() > 0){
        int c1 = card1[0];
        int c2 = card2[0];
        if(c1 > c2){
            card1.push_back(c2);
            card1.push_back(c1);
            s1 += c2;
            s2 -= c2;
        } else {
            card2.push_back(c1);
            card2.push_back(c2);
            s2 += c1;
            s1 -= c1;
        }
        num_seen[s1 * s2]++;
        card1.erase(card1.begin());
        card2.erase(card2.begin());
        fights++;
        if(num_seen[s1 * s2] > 20){
            cout << "-1\n";
            return 0;
        }
    }

    cout << fights << " ";
    if(card1.size() > 0){
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}
