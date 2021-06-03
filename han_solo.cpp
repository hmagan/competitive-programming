#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, y;
	cin >> n >> x >> y;

	set<double> s;
	bool undef = false;

	for(int i = 0; i < n; i++){
		int xi, yi;
		cin >> xi >> yi;
		if(x - xi == 0){ 
			undef = true; 
		} else {
			s.insert((y-yi)/ (double)(x-xi));
		}
	}

	cout << s.size() + undef << "\n";
}
