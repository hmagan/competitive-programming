#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;
	vector<int> g;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	g = a;
	sort(g.begin(), g.end());	
	int idx1 = -1;
	int idx2 = -1;
	for(int i = 0; i < n; i++){
		if(a[i] != g[i]){
			idx1 = i;
			for(int j = n-1; j >= 0; j--){
				if(a[j] != g[j]){
					idx2 = j;
					break;
				}
			}
			break;
		}
	}
	if(idx1 == -1 && idx2 == -1){
		cout << "yes\n" << "1 1\n";
		return 0;
	}

	reverse(a.begin() + idx1, a.begin() + idx2 + 1);
	bool good = true;
	for(int i = 0; i < n; i++){
		if(a[i] != g[i]){
			good = false;
			break;
		}
	}

	if(good){
		cout << "yes\n" << idx1 + 1 << " " << idx2 + 1 << "\n";
	} else {
		cout << "no\n";
	}
}
