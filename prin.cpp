#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	while(t--){
		int n;
		cin >> n;

		string str;
		cin >> str;
		int idx = 0;
		int num = 0;
		string base = "";
		string last = "";
		while(true){
			bool good2 = false;
			for(int i = 0; i < 26; i++){
				string sub = base + alpha[i];
				bool good = true;
				for(int j = 0; j < n - sub.length() + 1; j++){
					if(str.substr(j, sub.length()) == sub){
						good = false;
						break;
					}
				}
				if(good){
					cout << sub << "\n";
					good2 = true;
					break;
				}
			}
			if(good2){
				break;
			} else {
				base = last + alpha[idx];
				idx++;
				if(idx == 26){
					last = "a";
					idx = 0;
				}
			}
		}	
	}
}
