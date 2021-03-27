#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int count = 0;
		int orig_idx = -1;
		for(int i = 0; i < n; i++){
			if(s[i] == '*'){
				s[i] = 'x';
				orig_idx = i;
				count++;
				break;
			}
		}
		for(int i = n - 1; i>= 0; i--){
			if(s[i] == '*'){
				s[i] = 'x';
				count++;
				break;
			}
		}
		int last = -1;
		for(int i = 0; i < n; i++){
			if(s[i] == '*'){
				last = i;
				break;
			}
		}
		while(true){
			bool good = true;
			if(last == -1){
				break;
			}
			for(int i = 0; i < n; i++){
				if(s[i] == 'x'){
					if(i - last > k){
						good = false;
						count++;
						int l_idx = i - k;
						while(true){
							if(s[l_idx] == '*'){
								s[l_idx] = 'x';
								break;
							}
							l_idx++;
						}
					}
					last = i;
					if(!good){
						last = orig_idx;
						break;
					}
				}
			}
			if(good){
				break;
			}
			
		}
		cout << count << "\n";
	}
}