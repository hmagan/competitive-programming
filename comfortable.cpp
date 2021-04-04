#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool valid_position(int x, int y){
	return x >= 0 && x <= 1000 && y >= 0 && y <= 1000;
}

bool is_comfortable(int x, int y){
	if(board[x][y] == 0){
		return false;
	}
	int count = 0;
	for(int i = 0; i < 4; i++){
		if(valid_position(x + dx[i], y + dy[i]) && board[x + dx[i]][y + dy[i]] == 1){
			count++;
		}
	}
	return count == 3;
}

int main()
{
	int n;
	cin >> n;
	
	int comfortable = 0;
	while(n--){
		int x, y;
		cin >> x >> y;
		
		for(int i = 0; i < 4; i++){
			if(valid_position(x + dx[i], y + dy[i]) && is_comfortable(x + dx[i], y + dy[i])){
				comfortable--;
			}
		}
		board[x][y] = 1;
		for(int i = 0; i < 4; i++){
			if(valid_position(x + dx[i], y + dy[i]) && is_comfortable(x + dx[i], y + dy[i])){
				comfortable++;
			}
		}
		if(is_comfortable(x, y)){
			comfortable++;
		}
		cout << comfortable << "\n";
	}
}