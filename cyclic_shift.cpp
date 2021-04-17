#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		//pay attention to int vs. long long
		long long n, k;
		cin >> n >> k;
		string a;
		cin >> a;
		
		string orig_a = a;
		string biggest = a;
		long long cycle = 0;
		long long add = 0;
		while(true){
			a = a.substr(1, n-1) + a.substr(0, 1);
			cycle++;
			for(int i = 0; i < n; i++){
				if(a[i] == '1' && biggest[i] == '0'){
					biggest = a;
					add = cycle;
					break;
				}
				if(a[i] == '0' && biggest[i] == '1'){
					break;
				}
			}
			//cout << "A: " << a << "\n";
			if(a == orig_a){
				break;
			}
		}
		//cout << "BIGGEST " << biggest << " and ADD " << add << "\n";
		//cout << "CYCLE " << cycle << "\n";
		cout << add + (cycle * (k-1)) << "\n";
	}
}