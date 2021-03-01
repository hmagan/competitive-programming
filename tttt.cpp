#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("tttt.in");
	ofstream fout ("tttt.out");
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	int board[3][3];
	vector<int> unique;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			char letter;
			fin >> letter;
			int num = letter - 'A';
			board[i][j] = num;
			bool uni = true;
			for(int k = 0; k < unique.size(); k++){
				if(unique[k] == num){
					uni = false;
					break;
				}
			}
			if(uni){
				unique.push_back(num);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < unique.size(); i++){
		bool good = false;
		for(int j = 0; j < 3; j++){
			if(board[j][0] == unique[i] && board[j][1] == board[j][0] && board[j][2] == board[j][1]){
				good = true;
				break;
			}
		}
		if(good){
			ans++;
			continue;
		}
		good = false;
		for(int j = 0; j < 3; j++){
			if(board[0][j] == unique[i] && board[1][j] == board[0][j] && board[2][j] == board[1][j]){
				good = true;
				break;
			}
		}
		if(good || (unique[i] == board[0][0] && board[1][1] == board[0][0] && board[2][2] == board[1][1]) || (unique[i] == board[0][2] && board[1][1] == board[0][2] && board[2][0] == board[1][1])){
			ans++;
		}
	}
	
	fout << ans << "\n";
	
	ans = 0;
	for(int i = 0; i < unique.size(); i++){
		for(int j = i + 1; j < unique.size(); j++){
			bool good = false;
			for(int k = 0; k < 3; k++){
				if((board[k][0] == unique[i] || board[k][0] == unique[j]) && (board[k][1] == unique[i] || board[k][1] == unique[j]) && (board[k][2] == unique[i] || board[k][2] == unique[j])){
					good = true;
					break;
				}
			}
			if(good){
				ans++;
				continue;
			}
			good = false;
			for(int k = 0; k < 3; k++){
				if((board[0][k] == unique[i] || board[0][k] == unique[j]) && (board[1][k] == unique[i] || board[1][k] == unique[j]) && (board[2][k] == unique[i] || board[2][k] == unique[j])){
					good = true;
					break;
				}
			}
			if(good || ((board[0][0] == unique[i] || board[0][0] == unique[j]) && (board[1][1] == unique[i] || board[1][1] == unique[j]) && (board[2][2] == unique[i] || board[2][2] == unique[j])) || ((board[0][2] == unique[i] || board[0][2] == unique[j]) && (board[1][1] == unique[i] || board[1][1] == unique[j]) && (board[2][0] == unique[i] || board[2][0] == unique[j]))){
				ans++;
			}
		}
	}
	
	fout << ans;
	
	return 0;
}