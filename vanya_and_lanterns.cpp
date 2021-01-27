#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	
	int lights[n];
	
	for(int i = 0; i < n; i++){
		cin >> lights[i];
	}
	
	int x = sizeof(lights) / sizeof(lights[0]);
	sort(lights, lights + x);
	
	
	double max = 0;
	for(int i = 0; i < n - 1; i++){
		int diff = lights[i+1] - lights[i];
		if(diff > max){
			max = diff;
		}
	}
	
	max /= 2.0;
	
	if(lights[0] > max){
		max = lights[0];
	}
	if(l - lights[n-1] > max){
		max = l - lights[n-1];
	}
	
	//std::fixed to remove scientific notation
	cout << fixed << max;
	
	return 0;
}