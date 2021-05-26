#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    long long n, r, avg;
    cin >> n >> r >> avg;

    long long total = 0;
    vector<pair<long long, long long>> exams;
    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        total += a;
        if(a < r){
            exams.push_back({b, a});
        }
    }
    long long points = (avg * n);
    
    if(points - total == 0){
        cout << "0\n";
        return 0;
    }

    long long essays = 0;
    sort(exams.begin(), exams.end());

    for(long long i = 0; i < exams.size(); i++){
        long long w = (r - exams[i].second);
        long long add = (w * exams[i].first);
        if(w + total >= points){
            while(w > 0 && total < points){
                total++;
                essays += exams[i].first;
                w--;
            }
            break;
        } else {
            total += w;
            essays += add;
        }
    }

    cout << essays << "\n";
}
