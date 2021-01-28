#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		int n, x;
		cin >> n >> x;
		
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		bool result = false;
		
		int countO = 0;
		int countE = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] % 2 == 0){
				countE++;
			} else {
				countO++;
			}
		}
		
		for(int i = 1; i <= countO && i <= x; i +=2){
			result = x - i <= countE;
		}
		
		string output = (result) ? "Yes\n" : "No\n";
		cout << output;
	}
	
	return 0;
}