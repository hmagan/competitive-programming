#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> strings;
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		int count = 0;
		for(int j = 0; j < strings.size(); j++){
			if(strings[j] < a){
				count++;
			}
		}
		cout << count << "\n";
		strings.push_back(a);
	}
}