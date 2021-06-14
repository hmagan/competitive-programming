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

unsigned long long MAX = 1e6;

set<unsigned long long> sieve(unsigned long long n){ //sieve of eratosthenes
	vector<bool> good(n + 1, true);
	for(unsigned long long i = 2; i * i <= n; i++){
		if(good[i]){
			for(unsigned long long j = i * i; j <= n; j += i){
				good[j] = false;
			}
		}
	}
	set<unsigned long long> ans;
	for(unsigned long long i = 2; i <= n; i++){
		if(good[i]){
			ans.insert(i);
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	unsigned long long n, m;
	cin >> n >> m;

	vector<vector<unsigned long long>> matrix(n, vector<unsigned long long>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}

	set<unsigned long long> primes = sieve(MAX);

	unsigned long long MIN = -1;
	for(int i = 0; i < n; i++){
		unsigned long long count = 0;
		for(int j = 0; j < m; j++){
			if(primes.find(matrix[i][j]) == primes.end()){
				count += (*primes.upper_bound(matrix[i][j]) - matrix[i][j]);
			}
		}
		if(count == 0){
			cout << "0\n";
			return 0;
		}
		if(count < MIN || MIN == -1){
			MIN = count;
		}
	}

	for(int j = 0; j < m; j++){
		unsigned long long count = 0;
		for(int i = 0; i < n; i++){
			if(primes.find(matrix[i][j]) == primes.end()){
				count += (*primes.upper_bound(matrix[i][j]) - matrix[i][j]);
			}
		}
		if(count == 0){
			cout << "0\n";
			return 0;
		}
		if(count < MIN){
			MIN = count;
		}
	}

	cout << MIN << "\n";
}
