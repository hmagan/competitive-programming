#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("censor.in");
	ofstream fout ("censor.out");
	
	string word;
	fin >> word;
	
	string censor;
	fin >> censor;
	
	string ans = "";
	for(int i = 0; i < word.length(); i++){
		ans += word[i];
		if(ans.length() >= censor.length()){
			if(ans.substr(ans.length() - censor.length(), censor.length()) == censor){
				//resize es mas rapido que usar substr
				ans.resize(ans.length() - censor.length());
			}
		}
	}
	fout << ans;
	
	return 0;
}
