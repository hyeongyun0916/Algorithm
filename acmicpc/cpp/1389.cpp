#include <bits/stdc++.h>
using namespace std;

// 플로이드 와샬(Floyd Warshall)
int main() {
    // freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n, vector<int>(n, 987654321));

	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		temp1 -= 1;
		temp2 -= 1;
		dist[temp1][temp2] = 1;
		dist[temp2][temp1] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
				}
			}
		}
	}

	int minValue = 987654321, answer = 0;
	for (int i = 0; i < n; i++) {
		int value = 0;
		for (int j = 0; j < n; j++) {
			value += dist[i][j];
		}
		if (minValue > value) {
			minValue = value;
			answer = i;
		}
	}

	cout << answer+1 << endl;

    return 0;
}