#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int matrix[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		int count = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int p = i; p < n; p++){
					for(int q = j; q < n; q++){
						//cout << i << " " << j << " (" << matrix[i][j] << ") vs " << p << " " << q << " (" << matrix[p][q] << ")\n";
						if(i <= p && j <= q && matrix[i][j] > matrix[p][q]){
							count++;
						}
					}
				}
			}
		}
		cout << count << "\n";
	}
}