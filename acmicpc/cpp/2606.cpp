#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> coms;
int n, m;
int total = 0;

void findConnectCom(int current) {
	for (int i = 1; i < n+1; i++) {
		if (coms[current][i] == 1) {
			total++;
			for (int j = 1; j < n+1; j++) coms[j][i] = 0;
			findConnectCom(i);
		}
	}
}

int main() {
    // freopen("input.txt", "r", stdin);

	cin >> n >> m;
	coms.resize(n+1);
	for (int i = 0; i < n+1; i++) coms[i].resize(n+1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		coms[x][y] = 1;
		coms[y][x] = 1;
	}

	for (int j = 1; j < n+1; j++) coms[j][1] = 0;
	findConnectCom(1);
	cout << total << endl;

	return 0;
}