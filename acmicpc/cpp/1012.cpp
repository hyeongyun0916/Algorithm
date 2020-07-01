#include <bits/stdc++.h>
using namespace std;

int **farm;
int m, n, k;

void changeFarm(int x, int y) {
	if (0<=x&&x<n && 0<=y&&y<m && farm[x][y] == 1) {
		farm[x][y] = -1;
		changeFarm(x-1,y);
		changeFarm(x,y-1);
		changeFarm(x+1,y);
		changeFarm(x,y+1);
	}
}

void printFarm() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << farm[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n >> k;
		farm = new int*[n];
		for (int i = 0; i < n; i++) {
			farm[i] = new int[m]{0,};
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			farm[y][x] = 1;
		}

		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j] == 1) {
					num++;
					changeFarm(i,j);
				}
			}
		}
		cout << num << endl;
		
		for (int i = 0; i < n; i++) {
			delete [] farm[i];
		}
		delete [] farm;
	}
    return 0;
}