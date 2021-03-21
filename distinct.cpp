#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	set<int> distinct;
	
	cin >> n;
	
	//2 ez
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		distinct.insert(x);
	}
	
	cout << distinct.size();
}