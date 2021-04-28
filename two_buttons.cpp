#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10000000;

queue<int> q;
vector<int> dist(MAX_N);
int n, m;

//first bfs :cool_face:
void bfs(){
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node * 2 < 2 * m && dist[node*2] == -1){
            dist[node*2] = dist[node] + 1;
            q.push(node*2);
        }
        if(node > 0 && dist[node-1] == -1){
            dist[node-1] = dist[node] + 1;
            q.push(node - 1);
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    fill(dist.begin(), dist.end(), -1);

    dist[n] = 0;
    q.push(n);

    bfs();
    cout << dist[m];
}