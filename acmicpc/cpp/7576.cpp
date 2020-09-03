#include <bits/stdc++.h>
using namespace std;

/*
첫번째 시도는 이중 for문을 돌면서 새롭게 바뀐것 주변에 있는것을 바꾸는 식 => 시간초과
두번째 시도는 0에서 가장 가까운 1을 찾는 식 => 시간 초과
세번째 시도는 첫번째 시도에서 새롭게 바뀐 것을 for문을 통해서가 아닌 queue를 통해서 찾음 => 성공
*/

struct Node {
    int x;
    int y;
	int level;
    Node(int _x, int _y, int _level)
     : x(_x), y(_y), level(_level) {}
};

vector<vector<int>> direct = {{-1,0}, {0,-1}, {1,0}, {0,1}};
vector<vector<int>> tomatos;
int n, m, totalTomatos, answer;
queue<Node> q;

int main() {
    // freopen("input.txt", "r", stdin);

	cin >> m >> n;
	tomatos.resize(n);
	for (int i = 0; i < n; i++) {
		tomatos[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 0) {
				totalTomatos++;
			} else if (tomatos[i][j] == 1) {
				q.push(Node(i, j, 0));
			}
		}
	}

	while (!q.empty()) {
		Node front = q.front();
		q.pop();
		for (int k = 0; k < direct.size(); k++) {
			int newX = front.x + direct[k][0];
			int newY = front.y + direct[k][1];

			if (0 <= newX && newX < n && 0 <= newY && newY < m
			&& tomatos[newX][newY] == 0) {
				tomatos[newX][newY] = 1;
				totalTomatos -= 1;
				answer = front.level+1;
				q.push(Node(newX, newY, answer));
			}
		}
	}


	cout << (totalTomatos ? -1 : answer) << endl;

	return 0;
}



/*
struct Node {
    int x;
    int y;
	int level;
	vector<vector<int>> route;
    Node(int _x, int _y, int _level, vector<vector<int>> _route)
     : x(_x), y(_y), level(_level), route(_route) {}
};

int bfs(int x, int y) {
	int minLen = 987654321;
	queue<Node> q;
	vector<vector<bool>> visited(n);
    fill(visited.begin(), visited.end(), vector<bool> (m, false));

	q.push(Node(x, y, 0, {{x,y}}));
	while (!q.empty()) {
		Node current = q.front();
		q.pop();
		for (int i = 0; i < direct.size(); i++) {
			int newX = current.x + direct[i][0];
			int newY = current.y + direct[i][1];

			if (0 <= newX && newX < n && 0 <= newY && newY < m
			&& tomatos[newX][newY] != -1 && !visited[newX][newY]) {
				if (tomatos[newX][newY] == -2) {
					for (int j = 0; j < current.route.size(); j++) {
						tomatos[current.route[current.route.size()-j-1][0]][current.route[current.route.size()-j-1][1]] = j+1;
					}
					return current.level +1;
				} else if (tomatos[newX][newY] >= 0) {
					visited[newX][newY] = true;
					vector<vector<int>> temp(current.route);
					temp.push_back({newX, newY});
					q.push(Node(newX, newY, current.level+1, temp));
				} else {
					for (int j = 0; j < current.route.size(); j++) {
						tomatos[current.route[current.route.size()-j-1][0]][current.route[current.route.size()-j-1][1]] = tomatos[newX][newY]+j+1;
					}
					return tomatos[newX][newY]+1;
				}
			}
		}
	}
	return minLen;
}

int main() {
    freopen("input.txt", "r", stdin);

	int answer = 0;

	cin >> m >> n;
	tomatos.resize(n);
	for (int i = 0; i < n; i++) {
		tomatos[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 1) {
				tomatos[i][j] = -2;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomatos[i][j] == 0) {
				tomatos[i][j] = bfs(i, j);
				if (tomatos[i][j] == 987654321) {
					cout << -1 << endl;
					return 0;
				}
				answer = max(answer, tomatos[i][j]);
			}
		}
	}

	cout << answer << endl;

	return 0;
}
*/


// int n, m, totalTomatos = 0, days = 1;

// int main() {
//     freopen("input.txt", "r", stdin);

// 	cin >> m >> n;
// 	tomatos.resize(n);
// 	for (int i = 0; i < n; i++) {
// 		tomatos[i].resize(m);
// 		for (int j = 0; j < m; j++) {
// 			cin >> tomatos[i][j];
// 			if (tomatos[i][j] == 0) {
// 				totalTomatos++;
// 			}
// 		}
// 	}

// 	bool isChanged = true;
// 	while (totalTomatos > 0 && isChanged) {
// 		isChanged = false;
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < m; j++) {
// 				if (tomatos[i][j] == days) {
// 					for (int k = 0; k < direct.size(); k++) {
// 						int newX = i + direct[k][0];
// 						int newY = j + direct[k][1];

// 						if (0 <= newX && newX < n && 0 <= newY && newY < m
// 						&& tomatos[newX][newY] == 0) {
// 							tomatos[newX][newY] = days+1;
// 							isChanged = true;
// 							totalTomatos -= 1;
// 						}
// 					}
// 				}
// 			}
// 		}
// 		days++;
// 	}

// 	cout << (totalTomatos ? -1 : days-1) << endl;

// 	return 0;
// }