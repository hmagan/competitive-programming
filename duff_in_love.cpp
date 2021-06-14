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
	
	long long n;
	cin >> n;

	for(long long i = 10000000; i >= 2; i--){
		while(n % (i * i) == 0){
			n /= i;
		}
	}

	cout << n << "\n";
}
