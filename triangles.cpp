#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin ("triangles.in");
	ofstream fout ("triangles.out");
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	int n;
	fin >> n;
	
	int points[n][2];
	for(int i = 0; i < n; i++){
		fin >> points[i][0] >> points[i][1];
	}
	
	int m_area = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				int longx, longy = -1;
				//it's ugly i know
				if(points[i][0] == points[j][0]){
					longx = abs(points[i][1] - points[j][1]);
				} else if(points[j][0] == points[k][0]){
					longx = abs(points[j][1] - points[k][1]);
				} else if(points[i][0] == points[k][0]){
					longx = abs(points[i][1] - points[k][1]);
				}
				if(points[i][1] == points[j][1]){
					longy = abs(points[i][0] - points[j][0]);
				} else if(points[j][1] == points[k][1]){
					longy = abs(points[j][0] - points[k][0]);
				} else if(points[i][1] == points[k][1]){
					longy = abs(points[i][0] - points[k][0]);
				}
				if(longx != -1 && longy != -1){
					int area = longx * longy;
					m_area = max(m_area, area);
				}
			}
		}
	}
	
	fout << m_area;
	
	return 0;
}