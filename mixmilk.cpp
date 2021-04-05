#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("mixmilk.in");
    ofstream cout("mixmilk.out");
	
	long long c1, m1, c2, m2, c3, m3;
	cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
	
	int turn = 1;
	for(int i = 0; i < 100; i++){
		switch(turn){
			case 1:
				if(c2 >= m2 + m1){
					m2 += m1;
					m1 = 0;
				} else {
					m1 -= (c2-m2);
					m2 = c2;
				}
				turn = 2;
				break;
			case 2:
				if(c3 >= m3 + m2){
					m3 += m2;
					m2 = 0;
				} else {
					m2 -= (c3-m3);
					m3 = c3;
				}
				turn = 3;
				break;
			case 3:
				if(c1 >= m1 + m3){
					m1 += m3;
					m3 = 0;
				} else {
					m3 -= (c1-m1);
					m1 = c1;
				}
				turn = 1;
				break;
			default: 
				cout << "CODE BROKE\n";
				break;
		}
		//cout << m1 << "\n" << m2 << "\n" << m3 << "\n======\n";
	}
	
	cout << m1 << "\n" << m2 << "\n" << m3;
}