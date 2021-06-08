#include <bits/stdc++.h>

using namespace std;

int MAX = 1e5+1;

int n, m;
int c = 0;

vector<int> a(MAX);
vector<vector<int>> tree(MAX);

queue<pair<int, int>> q;
vector<bool> visited(MAX, false);

void bfs(){
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop();
		bool bad = a[curr.first];
		if(bad){
			curr.second++;
		}
		visited[curr.first] = true;
		if(curr.second <= m){
			int num = 0;
			for(int i = 0; i < tree[curr.first].size(); i++){
				if(!visited[tree[curr.first][i]]){
					int cats = ((bad) ? curr.second : 0);
					q.push({tree[curr.first][i], cats});
					num++;
				}
			}
			if(num == 0){
				c++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n-1; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	visited[0] = true;
	q.push({0, 0});

	bfs();

	cout << c << "\n";
}
