#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	while(n--){
		int total = 0;
		
		string path;
		cin >> path;
		
		for(int i = 0; i < path.size() - 1; i++){
			switch(path[i]){
				case 'N':
					switch(path[i+1]){
						case 'N':
							total += 0;
							break;
						case 'S':
							total += 0;
							break;
						case 'E':
							total += 90;
							break;
						case 'W':
							total -= 90;
							break;
						default: 
							cout << "BROKEN\n";
					}
					break;
				case 'S':
					switch(path[i+1]){
						case 'N':
							total += 0;
							break;
						case 'S':
							total += 0;
							break;
						case 'E':
							total -= 90;
							break;
						case 'W':
							total += 90;
							break;
						default: 
							cout << "BROKEN\n";
					}
					break;
				case 'E':
					switch(path[i+1]){
						case 'N':
							total -= 90;
							break;
						case 'S':
							total += 90;
							break;
						case 'E':
							total += 0;
							break;
						case 'W':
							total += 0;
							break;
						default: 
							cout << "BROKEN\n";
					}
					break;
				case 'W':
					switch(path[i+1]){
						case 'N':
							total += 90;
							break;
						case 'S':
							total -= 90;
							break;
						case 'E':
							total += 0;
							break;
						case 'W':
							total += 0;
							break;
						default: 
							cout << "BROKEN\n";
					}
					break;
				default: 
					cout << "BROKEN\n";
			}
		}
		if(total > 0){
			cout << "CW\n";
		} else {
			cout << "CCW\n";
		}
		//cout << (total == 360) ? "CW\n" : "CCW\n";
	}
}