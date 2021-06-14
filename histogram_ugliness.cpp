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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];	
		}

		if(n == 1){
			cout << a[0] << "\n";
			continue;
		}

		long long operations = 0;
		for(int i = 0; i < n; i++){
			if(i == 0){
				if(a[i] > a[i+1]){
					operations += a[i] - a[i+1];
					a[i] = a[i+1];
				}
			} else if(i == n - 1){
				if(a[i] > a[i-1]){
					operations += a[i] - a[i-1];
					a[i] = a[i-1];
				}
			} else {
				if(a[i-1] < a[i] && a[i+1] < a[i]){
					if(a[i] - a[i-1] < a[i] - a[i+1]){
						operations += a[i] - a[i-1];
						a[i] = a[i-1];
					} else {
						operations += a[i] - a[i+1];
						a[i] = a[i+1];	
					}
				}
			}
		}
		long long total = 0;
		for(int i = 1; i < n; i++){
			total += abs(a[i] - a[i-1]);
		}
		total += a[0];
		total += a[n-1];
		total += operations;
		cout << total << "\n";
	}	
}
