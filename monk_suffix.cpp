#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int k;
	cin >> s >> k;
	vector<string> suffixes;
	for(int i = s.length()-1; i >= 0; i--){
		suffixes.push_back(s.substr(i, s.length()-i));
	}
	sort(suffixes.begin(), suffixes.end());
	cout << suffixes[k-1];
}