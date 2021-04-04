#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("lostcow.in");
    ofstream cout("lostcow.out");
	
	int x, y;
	cin >> x >> y;
	
	int orig_x = x;
	bool x_less = x < y;
	
	int total = 0;
	int diff = 0;
	while(true){
		if(diff == 0){
			diff = 1;
		} else {
			diff *= -2;
		}
		total += abs(diff);
		total += abs(orig_x - x);
		x = orig_x + diff;
		if((x_less && x >= y) || (!x_less && x <= y)){
			total -= abs(y-x);
			break;
		}
	}
	
	cout << total;
}