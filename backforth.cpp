#include <bits/stdc++.h>

using namespace std;

bool possible_answers[2000];

void friday(int milk, vector<int> b1, vector<int> b2){
	for(int i = 0; i < b2.size(); i++){
		possible_answers[milk + b2[i]] = true;
	}
}

void thursday(int milk, vector<int> b1, vector<int> b2){
	for(int i = 0; i < b1.size(); i++){
		vector<int> temp(b1);
		vector<int> temp2(b2);
		temp.erase(temp.begin() + i);
		temp2.push_back(b1[i]);
		friday(milk - b1[i], temp, temp2);
	}	
}

void wednesday(int milk, vector<int> b1, vector<int> b2){
	for(int i = 0; i < b2.size(); i++){
		vector<int> temp(b1);
		vector<int> temp2(b2);
		temp2.erase(temp2.begin() + i);
		temp.push_back(b2[i]);
		thursday(milk + b2[i], temp, temp2);
	}
}

void tuesday(int milk, vector<int> b1, vector<int> b2){
	for(int i = 0; i < b1.size(); i++){
		vector<int> temp(b1);
		vector<int> temp2(b2);
		temp.erase(temp.begin() + i);
		temp2.push_back(b1[i]);
		wednesday(milk - b1[i], temp, temp2);
	}
}

int main()
{
	ifstream fin("backforth.in");
    ofstream fout("backforth.out");
	
	int ans = 0;
	
	vector<int> barn_one;
	vector<int> barn_two;
	
	int x;
	for(int i = 0; i < 10; i++){
		fin >> x;
		barn_one.push_back(x);
	}
	for(int i = 0; i < 10; i++){
		fin >> x;
		barn_two.push_back(x);
	}
	
	tuesday(1000, barn_one, barn_two);
	
	for(int i = 0; i < 2000; i++){
		if(possible_answers[i]){
			ans++;
		}
	}
	
	fout << ans;
}