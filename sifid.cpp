#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		vector<int> copy = a;
		sort(copy.begin(), copy.end());

		int ans = 0;
		int lowest = 1e9;
		int biggest = -1;
		for(int i = 0; i < n; i++){
			//cout << "b " << biggest << " s " << lowest << "\n";
			bool good = true;
			if(copy[i] > biggest){
				if(copy[i] - biggest < lowest){
					lowest = copy[i] - biggest;
				}
				biggest = copy[i];
				if(lowest < biggest){
					good = false;
					break;
				}
			} else {
				for(int j = 0; j < i; j++){
					if(abs(copy[j]-copy[i] < lowest)){
						lowest = abs(copy[j]-copy[i]);
					}
					if(copy[j] > copy[i]){
						break;
					}
				}
				if(lowest < biggest){
					good = false;
				}
			}
			biggest = copy[i];
			if(good){
				ans++;
			} else {
				break;
			}
		}
		cout << ans << "\n";
	}
 }
