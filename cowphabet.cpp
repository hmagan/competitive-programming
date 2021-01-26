#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string alpha;
	cin >> alpha;
	
	string word;
	cin >> word;
	
	int count = 0;
	int length = 0;
	
	while(length < word.length()){
		count++;
		for(int i = 0; i < 26; i++){
			if(word[length] == alpha[i]){
				length++;
			}
		}
	}
	
	cout << count;
	
	return 0;
}
