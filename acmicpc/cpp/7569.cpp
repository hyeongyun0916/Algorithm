#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x;
    int y;
	int z;
	int level;
    Node(int _x, int _y, int _z, int _level)
     : x(_x), y(_y), z(_z), level(_level) {}
};

vector<vector<int>> direct = {{-1,0,0}, {0,-1,0}, {0,0,-1}, {1,0,0}, {0,1,0}, {0,0,1}};
vector<vector<vector<int>>> tomatos;
int n, m, h, totalTomatos, answer;
queue<Node> q;

int main() {
    // freopen("input.txt", "r", stdin);

	cin >> m >> n >> h;
	tomatos.resize(h);
	for (int i = 0; i < h; i++) {
		tomatos[i].resize(n);
		for (int j = 0; j < n; j++) {
			tomatos[i][j].resize(m);
			for (int k = 0; k < m; k++) {
				cin >> tomatos[i][j][k];
				if (tomatos[i][j][k] == 0) {
					totalTomatos++;
				} else if (tomatos[i][j][k] == 1) {
					q.push(Node(i, j, k, 0));
				}
			}
		}
	}

	while (!q.empty()) {
		Node front = q.front();
		q.pop();
		for (int k = 0; k < direct.size(); k++) {
			int newX = front.x + direct[k][0];
			int newY = front.y + direct[k][1];
			int newZ = front.z + direct[k][2];

			if (0 <= newX && newX < h && 0 <= newY && newY < n && 0 <= newZ && newZ < m
			&& tomatos[newX][newY][newZ] == 0) {
				totalTomatos -= 1;
				answer = front.level+1;
				tomatos[newX][newY][newZ] = answer;
				q.push(Node(newX, newY, newZ, answer));
			}
		}
	}


	cout << (totalTomatos ? -1 : answer) << endl;

	return 0;
}