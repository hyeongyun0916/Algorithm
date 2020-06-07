#include <bits/stdc++.h>
using namespace std;

void printVector(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> dp;
	vector<int> numbers;
	
	for (int i = 0; i < n; i++) {
		vector<int> temp(n, 987654321);
		dp.push_back(temp);
	}
	

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	
	dp[0][0] = numbers[0];
	
	
	// 1 2 3 4 5
	// 9 10 11 7 8 5 6 7
	for (int i = 1; i < n; i++) {
		bool isChanged = false;
	
		for (int j = n -1; j >= 0; j--) {
			dp[i][j] = dp[i-1][j];
			if (!isChanged && dp[i-1][j] < numbers[i]) {
				dp[i][j+1] = numbers[i];
				isChanged = true;
			}
		}	
		if (!isChanged && dp[i-1][0] > numbers[i]) {
			dp[i][0] = numbers[i];
		}
	}
	
	// printVector(dp);
	
	for (int i = n; i > 0; i--) {
		if (dp[n-1][i-1] != 987654321) {
			cout << i << endl;
			break;
		}
	}
	
    return 0;
}