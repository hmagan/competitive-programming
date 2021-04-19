#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n;
		cin >> n;
		string str;
		cin >> str;
		cout << "Case #" << i << ": ";
		for(int j = 0; j < n; j++){
			int maxi = 1;
			for(int k = j; k >= 0; k--){
				if(k > 0 && str[k] > str[k-1]){
					maxi++;
				} else {
					break;
				}
			}
			cout << maxi << " ";
		}
		cout << "\n";
	}
}