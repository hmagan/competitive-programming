#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string lr, s;
	cin >> lr >> s;
	
	char keyboard[] = {
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 
		'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'
	};
	if(lr == "R"){
		for(int i = 0; i < s.size(); i++){
			int idx = -1;
			for(int j = 0; j < 30; j++){
				if(s[i] == keyboard[j]){ 
					idx = j;
					break;
				}
			}
			cout << keyboard[idx-1];
		}
	} else {
		for(int i = 0; i < s.size(); i++){
			int idx = -1;
			for(int j = 0; j < 30; j++){
				if(s[i] == keyboard[j]){
					idx = j;
					break;
				}
			}
			cout << keyboard[idx+1];
		}
	}
}