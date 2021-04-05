#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("buckets.in");
    ofstream cout("buckets.out");
	
	char grid[10][10];
	
	//barn, lake, rock
	int things[3][2];
	for(int i = 0; i < 10; i++){
		string row;
		cin >> row;
		for(int j = 0; j < 10; j++){
			grid[i][j] = row[j];
			if(grid[i][j] == 'B'){
				things[0][0] = i;
				things[0][1] = j;
			} else if(grid[i][j] == 'L'){
				things[1][0] = i;
				things[1][1] = j;
			} else if(grid[i][j] == 'R'){
				things[2][0] = i;
				things[2][1] = j;
			}
		}
	}
	int ans = abs(things[1][0] - things[0][0]) + abs(things[1][1] - things[0][1]) - 1;
	if(things[0][0] == things[1][0]){
		if(things[2][0] == things[0][0] && ((things[2][1] > things[1][1] && things[2][1] < things[0][1]) || (things[2][1] < things[1][1] && things[2][1] > things[0][1]))){
			cout << ans + 2;
		} else {
			cout << ans;
		}
	} else if(things[0][1] == things[1][1]){
		if(things[2][1] == things[0][1] && ((things[2][0] > things[1][0] && things[2][0] < things[0][0]) || (things[2][0] < things[1][0] && things[2][0] > things[0][0]))){
			cout << ans + 2;
		} else {
			cout << ans;
		}
	} else {
		cout << ans;
	}
}