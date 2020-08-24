#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> direct = {{-1,0}, {0,-1}, {1,0}, {0,1}};
vector<string> houses;
vector<int> counts;
int n;

int countHouse(int x, int y) {
	int total = 1;
	houses[x][y] = '0';
	for (int i = 0; i < direct.size(); i++) {
		int newX = x+direct[i][0];
		int newY = y+direct[i][1];

		if (0 <= newX && newX < n && 0 <= newY && newY < n 
		&& houses[newX][newY] == '1') 
			total += countHouse(newX, newY);
	}
	return total;
}

int main() {
    // freopen("input.txt", "r", stdin);

	cin >> n;
	houses.resize(n);
	for (int i = 0; i < n; i++) cin >> houses[i];

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (houses[i][j] == '1') {
				counts.push_back(countHouse(i, j));
			}
		}
	}

	sort(counts.begin(), counts.end());

	cout << counts.size() << endl;
	for (int i = 0; i < counts.size(); i++) cout << counts[i] << endl;

	return 0;
}