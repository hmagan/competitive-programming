/*
                                                                                             
                                                       .::                                   
    .::::    .::    .::: .:: .::    .::    .::     .:::.::        .::    .: .:::   .::       
   .::     .::  .::  .::  .:  .:: .:   .::  .::  :  .::.: .:    .:   .::  .::    .:   .::    
     .::: .::    .:: .::  .:  .::.::::: .:: .:: .:  .::.::  .::.::::: .:: .::   .::::: .::   
       .:: .::  .::  .::  .:  .::.:         .: .: .:.::.:   .::.:         .::   .:           
   .:: .::   .::    .:::  .:  .::  .::::   .:::    .:::.::  .::  .::::   .:::     .::::      
                                                                                             
                                                        .::                                  
                                                        .::  .::                             
              .::    .::     .::   .::    .: .:::     .:.: .:.::        .::                  
            .::  .::  .::   .::  .:   .::  .::          .::  .: .:    .:   .::               
           .::    .::  .:: .::  .::::: .:: .::          .::  .::  .::.::::: .::              
            .::  .::    .:.::   .:         .::          .::  .:   .::.:                      
              .::        .::      .::::   .:::           .:: .::  .::  .::::                 
                                                                                             
                                            .::                                              
                                 .:         .::                                              
               .: .:::   .::       .:: .::  .::         .::    .::     .:::                  
                .::    .::  .:: .:: .::  .::.:: .::   .::  .::  .::  :  .::                  
                .::   .::   .:: .:: .::  .::.::   .::.::    .:: .:: .:  .::                  
                .::   .::   .:: .:: .::  .::.::   .:: .::  .::  .: .: .:.::                  
               .:::     .:: .:::.::.:::  .::.:: .::     .::    .:::    .:::                  
                                                                                             
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k;

bool is_valid(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;

	set<pair<int, int>> good;
	vector<vector<char>> grid(n, vector<char>(m));
	stack<pair<int, int>> s;
	pair<int, int> start;
	int total = 0;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			grid[i][j] = s[j];
			if(grid[i][j] == '.'){
				total++;
				start = {i, j};
			}
		}
	}

	s.push(start);
	int dx[] = {0, 0, -1, 1};
	int dy[] = {1, -1, 0, 0};
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[start.first][start.second] = true;
	while(!s.empty()){
		pair<int, int> coord = s.top();
		s.pop();	
		good.insert(coord);
		if(total - k == good.size()){
			break;
		}
		for(int i = 0; i < 4; i++){
			pair<int, int> pot = {coord.first + dx[i], coord.second + dy[i]};
			if(is_valid(pot.first, pot.second) && grid[pot.first][pot.second] == '.' && !visited[pot.first][pot.second]){
				visited[pot.first][pot.second] = true;	
				s.push(pot);
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == '.'){
				if(good.find({i, j}) == good.end()){
					cout << "X";
				} else {
					cout << ".";
				}
			} else {
				cout << grid[i][j];
			}
		}
		cout << "\n";
	}
}
