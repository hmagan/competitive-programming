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

bool is_valid(int i, int j, int n, int m){
	return i >= 0 && i < n && j >= 0 && j < m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	while(t--){
		int n, m;
		cin >> n >> m;

		vector<vector<char>> grid(n, vector<char>(m));	
		queue<pair<int, int>> q;
		for(int i = 0; i < n; i++){
			string str;
			cin >> str;
			for(int j = 0; j < m; j++){
				grid[i][j] = str[j];
				if(grid[i][j] != '.'){
					q.push({i, j});
				}
			}
		}

		if(q.size() == 0){
			grid[0][0] = 'R';
			q.push({0, 0});
		}

		bool good = true;
		while(!q.empty()){
			pair<int, int> curr = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				pair<int, int> pot = {curr.first + dx[i], curr.second + dy[i]};
				if(is_valid(pot.first, pot.second, n, m)){
					if(grid[pot.first][pot.second] == '.'){
						grid[pot.first][pot.second] = ((grid[curr.first][curr.second] == 'R') ? 'W' : 'R');
						q.push(pot);
					} else {
						if(grid[curr.first][curr.second] == 'R'){
							if(grid[pot.first][pot.second] == 'R'){
								good = false;
								break;
							}
						} else {
							if(grid[pot.first][pot.second] == 'W'){
								good = false;
								break;
							}
						}
					}
				}
			}
			if(!good){
				break;
			}
		}

		if(good){
			cout << "YES\n";
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << grid[i][j];
				}
				cout << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}	
}
