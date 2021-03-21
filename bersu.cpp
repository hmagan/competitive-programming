#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	
	int boys[n];
	for(int i = 0; i < n; i++){
		cin >> boys[i];
	}
	
	cin >> m;
	int girls[m];
	for(int i = 0; i < m; i++){
		cin >> girls[i];
	}
	
	sort(boys, boys + sizeof(boys) / sizeof(boys[0]));
	sort(girls, girls + sizeof(girls) / sizeof(girls[0]));
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(abs(boys[i] - girls[j]) <= 1){
				answer++;
				girls[j] = 1001;
				break;
			}
		}
	}
	
	cout << answer;
}