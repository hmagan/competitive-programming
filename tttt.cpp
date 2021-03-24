#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("tttt.in");
    	ofstream fout("tttt.out");
	
	int board[3][3];
	vector<int> cows;
	
	for(int i = 0; i < 3; i++){
		string row;
		fin >> row;
		for(int j = 0; j < 3; j++){
			char cow = row[j];
			int c = cow - '0';
			board[i][j] = c;
			bool good = true;
			for(int k = 0; k < cows.size(); k++){
				if(cows[k] == c){
					good = false;
					break;
				}
			}
			if(good){
				cows.push_back(c);
			}
		}
	}
	
	int indiv = 0;
	for(int i = 0; i < cows.size(); i++){
		bool good = false;
		for(int j = 0; j < 3; j++){
			if(board[j][0] == cows[i] && board[j][1] == cows[i] && board[j][2] == cows[i]){
				good = true;
				break;
			}
		}
		if(good){
			indiv++;
			continue;
		}
		for(int j = 0; j < 3; j++){
			if(board[0][j] == cows[i] && board[1][j] == cows[i] && board[2][j] == cows[i]){
				good = true;
				break;
			}
		}
		if(good){
			indiv++;
			continue;
		}
		if(board[0][0] == cows[i] && board[1][1] == cows[i] && board[2][2] == cows[i]){
			good = true;
		}
		if(board[2][0] == cows[i] && board[1][1] == cows[i] && board[0][2] == cows[i]){
			good = true;
		}
		if(good){
			indiv++;
		}
	}
	fout << indiv << "\n";
	
	int group = 0;
	
	for(int i = 0; i < cows.size(); i++){
		for(int j = i + 1; j < cows.size(); j++){
			bool good = false;
			for(int k = 0; k < 3; k++){
				if((board[k][0] == cows[i] || board[k][0] == cows[j]) && (board[k][1] == cows[i] || board[k][1] == cows[j]) && (board[k][2] == cows[i] || board[k][2] == cows[j])){
					good = true;
					break;
				}
			}
			if(good){
				group++;
				continue;
			}
			for(int k = 0; k < 3; k++){
				if((board[0][k] == cows[i] || board[0][k] == cows[j]) && (board[1][k] == cows[i] || board[1][k] == cows[j]) && (board[2][k] == cows[i] || board[2][k] == cows[j])){
					good = true;
					break;
				}
			}
			if(good){
				group++;
				continue;
			}
			if((board[0][0] == cows[i] || board[0][0] == cows[j]) && (board[1][1] == cows[i] || board[1][1] == cows[j]) && (board[2][2] == cows[i] || board[2][2] == cows[j])){
				good = true;
			}
			if((board[2][0] == cows[i] || board[2][0] == cows[j]) && (board[1][1] == cows[i] || board[1][1] == cows[j]) && (board[0][2] == cows[i] || board[0][2] == cows[j])){
				good = true;
			}
			if(good){
				group++;
			}
		}
	}
	fout << group;
}
