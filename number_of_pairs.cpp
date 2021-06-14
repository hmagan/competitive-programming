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

long long MAX = 2 * 1e5;

vector<long long> a(MAX);

int lower(long long val, int l, int r){
	int ans = -1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] >= val){
			ans = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return ans;
}

int upper(long long val, int l, int r){
	int ans = -1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] <= val){
			ans = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long t;
	cin >> t;

	while(t--){
		long long n, l, r;
		cin >> n >> l >> r;

		a.resize(n);
		for(long long i = 0; i < n; i++){
			cin >> a[i];
		}

		sort(a.begin(), a.end());
		long long ans = 0;
		for(long long i = 0; i < n - 1; i++){
			int low = lower(l - a[i], i+1, n-1);
			int high = upper(r - a[i], i+1, n-1);
			if(low > -1 && high > -1){
				ans += high - low + 1;
			}
		}
		cout << ans << "\n";
	}	
}
