#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int one = 0;
		int two = 0;
		
		for(int i = 0; i < n; i++){
			int rev;
			cin >> rev;
			
			switch(rev){
				case 3:
					two++;
					break;
				case 2:
					one--;
					break;
				case 1:
					two++;
					break;
			}
		}
		cout << two << "\n";
	}
}