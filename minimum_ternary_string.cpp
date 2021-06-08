#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	cin >> a;

	int ones = 0;	
	for(int i = a.length() - 1; i >= 0; i--){
		if(a[i] == '1') ones++;
	}

	bool two = false;
	for(int i = 0; i < a.length(); i++){
		if(!two && a[i] == '2'){
			while(ones--){
				cout << "1";
			}
			cout << "2";
			two = true;
		} else if(a[i] == '0' || a[i] == '2'){
			cout << a[i];
		}
	}
	if(!two){
		while(ones--){
			cout << "1";
		}
	}

	cout << "\n";
}
