#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("traffic.in");
	ofstream fout ("traffic.out");
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	fin >> n;
	
	string flow[n];
	int lower[n];
	int higher[n];
	
	for(int i = 0; i < n; i++){
		fin >> flow[i] >> lower[i] >> higher[i];
	}
	
	//find prior to mile 1
	int idx = n;
	for(int i = 0; i < n; i++){
		if(flow[i] == "none"){
			idx = i;
		}
	}
	int l;
	int h;
	for(int i = idx; i >= 0; i--){
		if(i == idx){
			l = lower[i];
			h = higher[i];
		} else {
			if(flow[i] == "on"){
				l -= higher[i];
				h -= lower[i];
			} else if (flow[i] == "off"){
				l += lower[i];
				h += higher[i];
			} else {
				if(lower[i] > l){
					l = lower[i];
				}
				if(higher[i] < h){
					h = higher[i];
				}
			}
		}
	}
	fout << l << " " << h << "\n";
	
	
	//find after mile n
	for(int i = 0; i < n; i++){
		if(flow[i] == "none"){
			idx = i;
			break;
		}
	}
	for(int i = idx; i < n; i++){
		if(i == idx){
			l = lower[i];
			h = higher[i];
		} else {
			if(flow[i] == "on"){
				l += lower[i];
				h += higher[i];
			} else if(flow[i] == "off"){
				l -= higher[i];
				h -= lower[i];
			} else {
				if(lower[i] > l){
					l = lower[i];
				}
				if(higher[i] < h){
					h = higher[i];
				}
			}
		}
	}
	fout << l << " " << h;
	
	return 0;
}