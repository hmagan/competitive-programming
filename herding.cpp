#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("herding.in");
	ofstream fout ("herding.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int cows[3];
	
	fin >> cows[0] >> cows[1] >> cows[2];
	
	sort(cows, cows + (cows[0]/3));
	
	if(cows[1] == cows[0] + 1 && cows[2] == cows[1] + 1){
		fout << "0\n";
	} else if(cows[1] == cows[0] + 2 || cows[2] == cows[1] + 2){
		fout << "1\n";
	} else {
		fout << "2\n";
	}
	
	fout << max(cows[1] - cows[0], cows[2] - cows[1]) - 1;
	
	return 0;
}