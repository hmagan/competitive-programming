#include <bits/stdc++.h>

using namespace std;

int decToBin(int n){
	int binary[32];
	int i = 0;
	while(n > 0){
		binary[i] = n % 2;
		if(binary[i] == 1){
			return i;
		}
		n /= 2;
		i++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum, limit;
	cin >> sum >> limit;

	int ones = round(limit / 2.0);

	int start = limit;
	if(limit % 2 == 1){
		start--;
	}
	int total = 0;
	vector<int> nums;
	bool good = false;
	for(int i = start; i > 1; i-=2){
		int add = 0;
		if((double)log2(i) - (int)log2(i) == 0){
			add = i;
		} else {
			add = pow(2, decToBin(i));
		}
		if(total + add <= sum){
			total += add;
			nums.push_back(i);
		}
		if(total + ones >= sum){
			good = true;
			break;
		}
	}
	good = (total + ones >= sum);
	if(!good){
		cout << "-1\n";
		return 0;
	}
	int s = nums.size() + (sum - total);
	cout << s << "\n";
	for(int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	int odd = 1;
	while(total < sum){
		total++;
		cout << odd << " ";
		odd += 2;
	}
	cout << "\n";	
}
