#include <bits/stdc++.h>
using namespace std;

/*
answer[i][0]은 v[i-1]과 v[i]를 밟은것
answer[i][1]은 v[i-2]와 v[i]를 밟은것
*/

int main() {
    // freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	vector<int> v(n);
	vector<vector<int>> answer(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		answer[i].resize(2);
	}

	if (n == 1) {
		cout << v[0] << endl;
		return 0;
	}
	if (n == 2) {
		cout << v[0] + v[1] << endl;
		return 0;
	}

	answer[0][0] = answer[0][1] = v[0];
	answer[1][0] = v[1];
	answer[1][1] = v[0]+v[1];

	for (int i = 2; i < n; i++) {
		answer[i][0] = max(answer[i-2][0], answer[i-2][1]) + v[i];
		answer[i][1] = answer[i-1][0] + v[i];
	}

	cout << max(answer[n-1][0], answer[n-1][1]) << endl;

	return 0;
}