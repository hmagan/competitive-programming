/*
	This is awful code. You have been warned.
	At least it works.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string burger;
	cin >> burger;

	int nb, ns, nc;	
	cin >> nb >> ns >> nc;

	int pb, ps, pc;
	cin >> pb >> ps >> pc;

	long long r;
	cin >> r;

	int cb = 0, cs = 0, cc = 0;
	for(int i = 0; i < burger.length(); i++){
		switch(burger[i]){
			case 'B':
				cb++;
				break;
			case 'S':
				cs++;
				break;
			case 'C':
				cc++;
				break;
		}
	}

	bool zero[] = {false, false, false};
	if(cb == 0){
		zero[0] = true;
		cb = 1;
	}
	if(cs == 0){
		zero[1] = true;
		cs = 1;
	}
	if(cc == 0){
		zero[2] = true;
		cc = 1;
	}

	long long burgers = min(nb / cb, min(ns / cs, nc / cc));

	nb -= burgers * cb;
	ns -= burgers * cs;
	nc -= burgers * cc;

	if(zero[0]){
		cb = 101;
	}
	if(zero[1]){
		cs = 101;
	}
	if(zero[2]){
		cc = 101;
	}

	while((nb > cb || ns > cs || nc > cc) && r > 0){
		if(!zero[0] && nb < cb){
			r -= (cb - nb) * pb;
			nb = cb;
		}
		if(!zero[1] && ns < cs){
			r -= (cs - ns) * ps;
			ns = cs;
		}
		if(!zero[2] && nc < cc){
			r -= (cc - nc) * pc;
			nc = cc;
		}
		if(r >= 0){
			burgers++;
			nb -= cb;
			ns -= cs;
			nc -= cc;
		}
	}

	if(!zero[0] && nb < cb){
		r -= (cb - nb) * pb;
		nb = cb;
	}
	if(!zero[1] && ns < cs){
		r -= (cs - ns) * ps;
		ns = cs;
	}
	if(!zero[2] && nc < cc){
		r -= (cc - nc) * pc;
		nc = cc;
	}
	if(r >= 0){
		burgers++;
		nb -= cb;
		ns -= cs;
		nc -= cc;
	}

	if(zero[0]){
		cb = 0;
	}
	if(zero[1]){
		cs = 0;
	}
	if(zero[2]){
		cc = 0;
	}

	int total = (cb * pb) + (cs * ps) + (cc * pc);
	burgers += (r / total);

	cout << burgers << "\n";
}
