#include <bits/stdc++.h>

using namespace std;

int num_nines(long long x){
	int res = 0;
	while(x > 0){
		int digit = x % 10;
		if(digit == 9){
			res++;
			x /= 10;
		} else {
			break;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long d, p;	
	cin >> p >> d;

	int nines = num_nines(p);

	for(int k = 18; k >= 1; k--){
		if(k <= nines){
			break;
		}
		long long num = p - p % (long long) pow(10, k) - 1;
		if(num != -1){
			if(num >= p - d){
				cout << num << "\n";
				return 0;
			}
		}
	}

	cout << p << "\n";
}
