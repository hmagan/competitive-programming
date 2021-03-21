#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("angry.in");
	ofstream fout ("angry.out");
	
	int n;
	fin >> n;
	
	int cows[n];
	int r_cows[n];
	
	for(int i = 0; i < n; i++){
		int x;
		fin >> x;
		cows[i] = x;
		r_cows[i] = x;
	}
	
	sort(cows, cows + sizeof(cows) / sizeof(cows[0]));
	sort(r_cows, r_cows + sizeof(r_cows) / sizeof(r_cows[0]));
	
	int m_count = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cows[j] = r_cows[j];
		}
		//cout << "COW: " << r_cows[i] << "\n";
		int count = 0;
		int t = 0;
		vector<int> blow_up;
		blow_up.push_back(i);
		cows[i] = 981734;
		
		while(blow_up.size() > 0){
			t++;
			vector<int> new_blow;
			for(int j = 0; j < blow_up.size(); j++){
				//cout << "BLOWING UP COW: " << r_cows[blow_up[j]] << "\n";
				count++;
				for(int k = blow_up[j] + 1; k < n; k++){
					if(cows[k] == 981734){
						continue;
					}
					if(r_cows[k] <= r_cows[blow_up[j]] + t){
						new_blow.push_back(k);
						//cout << "ADDING COW: " << r_cows[k] << "\n";
						cows[k] = 981734;
					} else {
						break;
					}
				}
				for(int k = blow_up[j] - 1; k >= 0; k--){
					if(cows[k] == 981734){
						continue;
					}
					if(r_cows[k] >= r_cows[blow_up[j]] - t){
						new_blow.push_back(k);
						//cout << "ADDING COW: " << r_cows[k] << "\n";
						cows[k] = 981734;
					} else {
						break;
					}
				}
			}
			blow_up.clear();
			if(new_blow.size() > 0){
				for(int j = 0; j < new_blow.size(); j++){
					blow_up.push_back(new_blow[j]);
				}
			}
		}
		
		//cout << "COW: " << r_cows[i] << " BLEW UP " << count << " COWS" << "\n";
		
		//cout << "================================\n";
		
		if(count > m_count){
			m_count = count;
		}
	}
	
	fout << m_count;
}