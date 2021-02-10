#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("whereami.in");
	ofstream fout ("whereami.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string colors;
	
	fin >> n >> colors;
	int ans = 1;
	
	for(int i = 1; i <= n; i++){
		if(i == n){
			ans = n;
			break;
		}
		vector<string> distinct;
		bool all_unique = false;
		for(int j = 0; j < n - i + 1; j++){
			all_unique = true;
			bool broken = false;
			string seq = colors.substr(j, i);
			for(int k = 0; k < distinct.size(); k++){
				if(distinct[k] == seq){
					broken = true;
					break;
				}
			}
			distinct.push_back(seq);
			if(broken){
				all_unique = false;
				break;
			}
		}
		if(all_unique){
			ans = i;
			break;
		}
	}
	
	fout << ans;
	
	return 0;
}