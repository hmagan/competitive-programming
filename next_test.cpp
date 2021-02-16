#include <bits/stdc++.h>

using namespace std;

int main()
{
	//ifstream fin ("notlast.in");
	//ofstream fout ("notlast.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int list[n];
	for(int i = 0; i < n; i++){
		cin >> list[i];
	}
	
	sort(list, list + (sizeof(list)/sizeof(list[0])));
	
	int num = 1;
	bool lol = true;
	for(int i = 0; i < n; i++){
		if(list[i] != num){
			cout << num;
			lol = false;
			break;
		} else {
			num++;
		}
	}
	if(lol){
		cout << list[n-1] + 1;
	}
	return 0;
}