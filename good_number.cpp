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
	
	int n, k;
	cin >> n >> k;

	int count = 0;
	while(n--){
		string a;
		cin >> a;
		vector<bool> good(k+1, false);
		for(int i = 0; i < a.length(); i++){
			if(a[i] - '0' > k){
				continue;
			} else {
				good[a[i] - '0'] = true;
			}
		}
		bool check = true;
		for(int i = 0; i < good.size(); i++){
			if(!good[i]){
				check = false;
				break;
			}
		}
		if(check){
			count++;
		}
	}	

	cout << count << "\n";
}
