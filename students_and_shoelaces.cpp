#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<set<int>> students(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		students[a].insert(b);
		students[b].insert(a);
	}	

	bool good = true;
	int count = 0;
	while(good){
		good = false;
		set<int> del;
		for(int i = 0; i < n; i++){
			if(students[i].size() == 1){
				good = true;
				del.insert(i);
			}
		}
		if(good){
			count++;
		}
		for(int i = students.size() - 1; i >= 0; i--){
			if(del.find(i) != del.end()){
				students[i].clear();
			} else {
				for(auto it = del.begin(); it != del.end(); it++){
					if(students[i].find(*it) != students[i].end()){
						students[i].erase(*it);
					}
				}
			}
		}
	}

	cout << count << "\n";
}
