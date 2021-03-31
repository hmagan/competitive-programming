#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("swap.in");
    ofstream fout("swap.out");
	
	int n, k;
	fin >> n >> k;
	
	vector<int> cows;
	for(int i = 0; i < n; i++){
		cows.push_back(i + 1);
	}
	
	int steps[2][2];
	fin >> steps[0][0] >> steps[0][1] >> steps[1][0] >> steps[1][1];
	
	int count = 0;
	while(true){
		count++;
		reverse(cows.begin()+steps[0][0]-1, cows.begin()+steps[0][1]);
		reverse(cows.begin()+steps[1][0]-1, cows.begin()+steps[1][1]);
		bool good = true;
		for(int i = 0; i < n-1; i++){
			if(cows[i]+1 != cows[i+1]){
				good = false;
				break;
			}
		}
		if(good){
			break;
		}
	}
	
	for(int i = 0; i < k % count; i++){
		reverse(cows.begin()+steps[0][0]-1, cows.begin()+steps[0][1]);
		reverse(cows.begin()+steps[1][0]-1, cows.begin()+steps[1][1]);
	}
	
	for(int i : cows){
		fout << i << "\n";
	}
}