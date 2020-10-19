#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> nums;
	
	nums.push_back(1);
	nums.push_back(1);

	for (int i = 2; i <= n; i++) {
		nums.push_back((nums[i-1]+nums[i-2]+1)%1000000007);
	}
	
	cout << nums.back() << endl;

	return 0;
}