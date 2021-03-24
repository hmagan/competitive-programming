#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("family.in");
    ofstream fout("family.out");
	
	int n;
	string one, two;
	
	fin >> n >> one >> two;
	
	string relationships[n][2];
	for(int i = 0; i < n; i++){
		fin >> relationships[i][0] >> relationships[i][1];
	}
	
	vector<string> tree;
	string current = one;
	
	tree.push_back(current);
	
	while(true){
		bool longer = false;
		for(int i = 0; i < n; i++){
			if(relationships[i][1] == current){
				tree.push_back(relationships[i][0]);
				current = relationships[i][0];
				longer = true;
				break;
			}
		}
		if(!longer){
			break;
		}
	}
	
	vector<string> tree2;
	current = two;
	
	tree2.push_back(current);
	
	while(true){
		bool longer = false;
		for(int i = 0; i < n; i++){
			if(relationships[i][1] == current){
				tree2.push_back(relationships[i][0]);
				current = relationships[i][0];
				longer = true;
				break;
			}
		}
		if(!longer){
			break;
		}
	}
	
	int idx = -1;
	int idx2 = -1;
	
	for(int i = 1; i < tree.size(); i++){
		if(tree[i] == two){
			idx = 0;
			idx2 = i;
			break;
		}
	}
	
	if(idx != 0){
		for(int i = 1; i < tree2.size(); i++){
			if(tree2[i] == one){
				idx = i;
				idx2 = 0;
				break;
			}
		}
	}
	
	if(idx > 0 || idx2 > 0){
		bool one_bigger = idx > idx2;
		int diff = max(idx - idx2, idx2 - idx);
		if(one_bigger){
			fout << one << " is the ";
			if(diff == 1){
				fout << "mother ";
			} else if (diff == 2){
				fout << "grand-mother " ;
			} else {
				for(int i = 0; i < diff - 2; i++){
					fout << "great-";
				}
				fout << "grand-mother ";
			}
			fout << "of " << two;
		} else {
			fout << two << " is the ";
			if(diff == 1){
				fout << "mother ";
			} else if (diff == 2){
				fout << "grand-mother " ;
			} else {
				for(int i = 0; i < diff - 2; i++){
					fout << "great-";
				}
				fout << "grand-mother ";
			}
			fout << "of " << one;
		}
		return 0;
	}
	
	for(int i = 0; i < tree.size(); i++){
		bool good = false;
		for(int j = 0; j < tree2.size(); j++){
			if(tree[i] == tree2[j]){
				idx = i;
				idx2 = j;
				good = true;
				break;
			}
		}
		if(good){
			break;
		}
	}
	
	if(idx == -1 || idx2 == -1){
		fout << "NOT RELATED";
	} else {
		if(idx == 1 && idx2 == 1){
			fout << "SIBLINGS";
		} else if(idx == 1 || idx2 == 1){
			if(idx > idx2){
				fout << two << " is the ";
				int dist = idx - idx2;
				for(int i = 0; i < dist - 1; i++){
					fout << "great-";
				}
				fout << "aunt of " << one;
			} else {
				fout << one << " is the ";
				int dist = idx2 - idx;
				for(int i = 0; i < dist - 1; i++){
					fout << "great-";
				}
				fout << "aunt of " << two;
			}
		} else {
			fout << "COUSINS";
		}
	}
}