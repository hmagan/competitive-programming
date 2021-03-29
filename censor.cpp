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
	
	for(int i = 0; i < word.length() - censor.length(); i++){
		if(word.substr(i, censor.length()) == censor){
			word = word.substr(0, i) + word.substr(i + censor.length(), word.length() - i + censor.length());
			i -= censor.length();
			if(i < 0){
				i = 0;
			}
		}
	}
	fout << word;
	
	return 0;
}