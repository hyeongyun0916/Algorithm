#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> direct = {{-1,0}, {0,-1}, {1,0}, {0,1}};
vector<string> paints1, paints2;
int n;

int rgb1 = 0, rgb2 = 0;

void countPaints(int x, int y, int paint, vector<string> &paints) {
	paints[x][y] = '_';
	for (int i = 0; i < direct.size(); i++) {
		int newX = x + direct[i][0];
		int newY = y + direct[i][1];

		if (0 <= newX && newX < n && 0 <= newY && newY <= n
		&& paints[newX][newY] == paint)
			countPaints(newX, newY, paint, paints);
	}
}

int main() {
    // freopen("input.txt", "r", stdin);

	cin >> n;
	paints1.resize(n);
	for (int i = 0; i < n; i++) cin >> paints1[i];
	paints2.assign(paints1.begin(), paints1.end());

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
	if (paints2[i][j] == 'G') paints2[i][j] = 'R';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paints1[i][j] != '_') {
				rgb1++;
				countPaints(i, j, paints1[i][j], paints1);
			}
			if (paints2[i][j] != '_') {
				rgb2++;
				countPaints(i, j, paints2[i][j], paints2);
			}
		}
	}

	cout << rgb1 << " " << rgb2 << endl;

	return 0;
}