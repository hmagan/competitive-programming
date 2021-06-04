#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	vector<int> ascii(123, 0);

	for(int i = 0; i < t.length(); i++){
		ascii[(int)t[i]]++;
	}

	int yay = 0;
	int whoops = 0;
	vector<bool> v(s.length(), false);
	for(int i = 0; i < s.length(); i++){
		if(ascii[(int)s[i]] > 0){
			v[i]=true;
			ascii[(int)s[i]]--;
			yay++;
		}
	}
	
	for(int i = 0; i < s.length(); i++){
		bool caps = (int)s[i] <= 90;
		if(!v[i]){
			if(caps){
				if(ascii[(int)s[i] + 32] > 0){
					ascii[(int)s[i] + 32]--;
					whoops++;
				}
			} else {
				if(ascii[(int)s[i]-32] > 0){
					ascii[(int)s[i]-32]--;
					whoops++;
				}
			}
		}
	}

	cout << yay << " " << whoops << "\n";
}
