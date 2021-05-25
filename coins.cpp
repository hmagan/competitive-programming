#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    string compare[3];
    cin >> compare[0] >> compare[1] >> compare[2];
    string abc = "ABC";
    vector<char> coins(3, ' ');

    for(int i = 0; i < 3; i++){
        char letter = abc[i];
        bool less1 = false;
        bool less2 = false;
        for(int j = 0; j < 3; j++){
            if(compare[j][0] == letter){
                if(compare[j][1] == '<'){
                    int idx = -1;
                    for(int k = 0; k < 3; k++){
                        if(abc[k] == compare[j][2]){
                            idx = k;
                            break;
                        }
                    }
                    switch(letter){
                        case 'A':
                            if(idx == 1){
                                less1 = true;
                            } else {
                                less2 = true;
                            }
                            break;
                        case 'B':
                            if(idx == 0){
                                less1 = true;
                            } else {
                                less2 = true;
                            }
                            break;
                        case 'C':
                            if(idx == 0){
                                less1 = true;
                            } else {
                                less2 = true;
                            }
                            break;
                    }
                }
            } else if(compare[j][2] == letter){
                if(compare[j][1] == '>'){
                    int idx = -1;
                    for(int k = 0; k < 3; k++){
                        if(abc[k] == compare[j][0]){
                            idx = k;
                            break;
                        }
                    }
                    switch(letter){
                        case 'A':
                            if(idx == 1){
                                less1 = true;
                            } else {
                                less2 = true;
                            }
                            break;
                        case 'B':
                            if(idx == 0){
                                less1 = true;
                            } else {
                                less2 = true;
                            }
                            break;
                        case 'C':
                            if(idx == 0){
                                less1 = true;
                            } else {
                                less2 = true;
                            }
                            break;
                    }
                }
            }
        }
        if(less1 && less2){
            if(coins[0] != ' '){
                cout << "Impossible\n";
                return 0;
            } else {
                coins[0] = letter;
            }
        } else if(!less1 && !less2){
            if(coins[2] != ' '){
                cout << "Impossible\n";
                return 0;
            } else {
                coins[2] = letter;
            }
        } else {
            if(coins[1] != ' '){
                cout << "Impossible\n";
                return 0;
            } else {
                coins[1] = letter;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        cout << coins[i];
    }
    cout << "\n";
}