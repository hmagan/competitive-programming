#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("billboard.in");
	ofstream fout ("billboard.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	
	fin >> x3 >> y3 >> x4 >> y4 >> x1 >> y1 >> x2 >> y2;
	
	int l = x4 - x3;
	int w = y4 - y3;
	
	//find length
	if(x1 < x3){
		if(x2 > x3){
			if(y1 <= y3 && y2 >= y4){
				l = x4 - x2;
			}
		}
	} else if (x1 > x3){
		if(x2 < x4){
			if(y1 <= y3 && y2 >= y4){
				l = (x4 - x2) + (x1 - x3);
			}
		} else if (x2 >= x4){
			if(y1 <= y3 && y2 >= y4){
				l = x1 - x3;
			}
		}
	} else {
		if(y1 <= y3 && y2 >= y4){
			l = x4 - x2;
		}
	}
	
	//find width
	if(y1 > y3){
		if(y2 >= y4){
			if(x1 <= x3 && x2 >= x4){
				w = y1 - y3;
			}
		} else {
			if(x1 <= x3 && x2 >= x4){
				w = (y1 - y3) + (y4 - y2);
			}
		}
	} else if(y1 < y3){
		if(y2 >= y3){
			if(x1 <= x3 && x2 >= x4){
				w = y4 - y2;
			}
		}
	} else {
		if(x1 <= x3 && x2 >= x4){
			w = 0;
		}
	}
	
	if(l < 0){ l = 0; }
	if(w < 0){ w = 0; }
	
	fout << l * w;
	
	return 0;
}