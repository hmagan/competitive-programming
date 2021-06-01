#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string burger;
	cin >> burger;

	//BSC
	vector<int> cost(3, 0);
	for(int i = 0; i < burger.length(); i++){
		char x = burger[i];
		switch(x){
			case 'B':
				cost[0]++;
				break;
			case 'S':
				cost[1]++;
				break;
			case 'C':
				cost[2]++;
				break;
		}
	}	

	vector<int> n(3);
	vector<int> p(3);

	cin >> n[0] >> n[1] >> n[2]
			>> p[0] >> p[1] >> p[2];

	for(int i = cost.size()-1; i >= 0; i--){
		if(cost[i] == 0){
			cost.erase(cost.begin()+i);
			n.erase(n.begin()+i);
			p.erase(p.begin()+i);
		}
	}

	long long r;
	cin >> r;

	vector<int> orig = n;

	int max = 0;
	int c = 0;
	for(int i = 0; i < n.size(); i++){
		while(n[i] % cost[i] != 0){
			n[i]++;
			c += p[0];
			if(n[i] / cost[i] > max){
				max = n[i] / cost[i];
			}
		}
		if(n[i] / cost[i] > max){
			max = n[i] / cost[i];
		}
	}

	for(int i = 0; i < n.size(); i++){
		int haha = c;
		if(n[i]/cost[i] != max){
			c += (p[i] * (max - n[i]/cost[i]));
		}
		cout << "it took " << c - haha << " r to get " << i << " to " << max << "\n";
	}

	long long total = 0;

	if(c > r){
		n = orig;
		int start = INT_MAX;
		for(int i = 0; i < n.size(); i++){
			start = min(start, (n[i] / cost[i]));
		}
		total += start;

		for(int i = 0; i < n.size(); i++){
			n[i] -= (start * cost[i]);
		}

		while(r > 0){
			int diff[n.size()];
			int d = 0;
			for(int i = 0; i < n.size(); i++){
				diff[i] = (cost[i] - n[i]);
				if(diff[i] < 0){
					n[i] -= cost[i];
				} else {
					n[i] = 0;
					d += (diff[i] * p[i]);
				}
			}
			r -= d;
			if(r < 0){
				break;
			} else {
				total++;
			}
		}
	} else {
		cout << "c " << c << "\n";
		r -= c;
		total += max;
		for(int i = 0; i < n.size(); i++){
			n[i] = 0;
		}

		int full = 0;
		for(int i = 0; i < p.size(); i++){
			full += (p[i] * cost[i]);
		}
		cout << "r " << r << "  full " << full << "\n";

		total += (r / full);
	}

	cout << total << "\n";
}
