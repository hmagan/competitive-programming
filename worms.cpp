#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int worms[n];
	for(int i = 0; i < n; i++){
		cin >> worms[i];
	}
	
	int m;
	cin >> m;
	
	int marmot[m];
	for(int i = 0; i < m; i++){
		cin >> marmot[i];
	}
	
	int upper[n];
	for(int i = 0; i < n; i++){
		if(i == 0){
			upper[i] = worms[i];
		} else {
			upper[i] = upper[i-1] + worms[i];
		}
	}
	
	///binary search for each worm to manage time complexity
	for(int i = 0; i < m; i++){
		int lowest = upper[0];
		int low = 0;
		int high = n;
		while(low <= high){
			int mid = (high + low) / 2;
			if(marmot[i] <= upper[mid] && marmot[i] > upper[mid-1]){
				lowest = mid;
				break;
			}
			if(upper[mid] < marmot[i]){
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << lowest + 1 << "\n";
	}
	
	return 0;
}