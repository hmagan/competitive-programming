#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;

	long long LCM = std::lcm(a, b);
	
	long long d = LCM / a;
	long long m = LCM / b;
	
	if(a > b){
		d++;
	} else {
		m++;
	}

	if(m > d){
		cout << "Masha\n";
	} else if(d > m){
		cout << "Dasha\n";
	} else {
		cout << "Equal\n";
	}
}
