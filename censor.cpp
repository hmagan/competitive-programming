#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("censor.in");
	ofstream fout ("censor.out");
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	string word;
	string text;
	
	fin >> text >> word;
	
	int len = word.length();
	
	int idx = 0;
	while(idx < text.length() - len + 1){
		if(text.substr(idx, len) == word){
			text = text.substr(0, idx) + text.substr(idx + len, text.length() - 1);
			idx -= len;
			if(idx < 0){
				idx = 0;
			}
		} else {
			idx++;
		}
	}
	
	fout << text;
	
	return 0;
}