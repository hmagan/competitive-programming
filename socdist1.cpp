#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("socdist1.in");
    ofstream fout("socdist1.out");
	
	int n;
	fin >> n;
	
	string cows;
	fin >> cows;
	
	int most = -1;
	int sec_most = -1;
	int last_cow;
	for(int i = 0; i < n; i++){
		if(cows[i] == '1'){
			last_cow = i;
			most = i;
			break;
		}
	}
	for(int i = last_cow + 1; i < n; i++){
		if(cows[i] == '1'){
			if(i - last_cow > most){
				sec_most = most;
				most = i - last_cow;
			} else if(i - last_cow > sec_most){
				sec_most = i - last_cow;
			}
			last_cow = i;
		}
	}
	if(most == -1 && sec_most == -1){
		fout << n-1;
	} else if(sec_most == -1){
		fout << max(n-1-most, most)/2;
	} else {
		if(most/3 > sec_most/2){
			fout << most/3;
		} else {
			fout << sec_most/2;
		}
	}
}