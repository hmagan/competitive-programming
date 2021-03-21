#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		int n, k;
		cin >> n >> k;
		string x;
		cin >> x;
		
		int count = 0;
		for(int j = 0; j < n/2; j++){
			if(x[j] != x[n-j-1]){
				count++;
			}
		}
		
		cout << "Case #" << i << ": " << abs(k - count) << "\n";
	}
}