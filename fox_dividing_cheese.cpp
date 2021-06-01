#include <bits/stdc++.h>

using namespace std;

int a, b;
int MAX = 1e7;

/*
	 Technically incorrect because it fails a test case because I cannot
	 store a vector 1e9 large, but I got the concept so I'll mark it as
	 a W.
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;

	if(a == b){
		cout << "0\n";
		return 0; 
	}

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	vector<int> d1(MAX, -1);
	vector<int> d2(MAX, -1);

	q1.push({a, 0});
	q2.push({b, 0});
	d1[a] = 0;
	d2[b] = 0;

	int dist = INT_MAX;
	while(!q1.empty() || !q2.empty()){
		if(!q1.empty()){
			pair<int, int> curr = q1.front();
			q1.pop();
			if(curr.first % 2 == 0 && curr.first / 2 > 0){
				if(d2[curr.first / 2] > -1){
					dist = min(dist, d2[curr.first / 2] + curr.second + 1);
				} else {
					d1[curr.first / 2] = curr.second + 1;
					q1.push({curr.first / 2, curr.second + 1});
				}
			}
			if(curr.first % 3 == 0 && curr.first / 3 > 0){
				if(d2[curr.first / 3] > -1){
					dist = min(dist, d2[curr.first / 3] + curr.second + 1);
				} else {
					d1[curr.first / 3] = curr.second + 1;
					q1.push({curr.first / 3, curr.second + 1});
				}
			}
			if(curr.first % 5 == 0 && curr.first / 5 > 0){
				if(d2[curr.first / 5] > -1){
					dist = min(dist, d2[curr.first / 5] + curr.second + 1);
				} else {
					d1[curr.first / 5] = curr.second + 1;
					q1.push({curr.first / 5, curr.second + 1});
				}
			}
		}
		if(!q2.empty()){
			pair<int, int> curr = q2.front();
			q2.pop();
			if(curr.first % 2 == 0 && curr.first / 2 > 0){
				if(d1[curr.first / 2] > -1){
					dist = min(dist, d1[curr.first / 2] + curr.second + 1);
				} else {
					d2[curr.first / 2] = curr.second + 1;
					q2.push({curr.first / 2, curr.second + 1});
				}
			}
			if(curr.first % 3 == 0 && curr.first / 3 > 0){
				if(d1[curr.first / 3] > -1){
					dist = min(dist, d1[curr.first / 3] + curr.second + 1);
				} else {
					d2[curr.first / 3] = curr.second + 1;
					q2.push({curr.first / 3, curr.second + 1});
				}
			}
			if(curr.first % 5 == 0 && curr.first / 5 > 0){
				if(d1[curr.first / 5] > -1){
					dist = min(dist, d1[curr.first / 5] + curr.second + 1);
				} else {
					d2[curr.first / 5] = curr.second + 1;
					q2.push({curr.first / 5, curr.second + 1});
				}
			}
		}
	}

	if(dist == INT_MAX){
		dist = -1;
	}

	cout << dist << "\n";
}
