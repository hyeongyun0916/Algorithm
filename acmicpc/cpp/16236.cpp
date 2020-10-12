#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> direct = {{-1,0}, {0,-1}, {0,1}, {1,0}};
vector<vector<int>> spaces;
int n;
int sharkX, sharkY, sharkSize;
int answer = 0;


/*
단순 bfs로 풀면,
0 0 9 0 1
0 1 0 0 0
0 0 0 0 0
위와 같은 상황에서
오른쪽 1이 아닌 왼쪽 밑에 1을 먹음
*/

struct Node {
    int x;
    int y;
	int count;
    Node(int _x, int _y, int _count)
     : x(_x), y(_y), count(_count) {}
};

int gotoNearFish(int x, int y) {
	queue<Node> routes;
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	routes.push(Node(x, y, 0));
	visited[x][y] = true;

	bool find = false;
	int returnCount = 0;
	while (!routes.empty()) {
		Node current = routes.front();
		routes.pop();
		for (int i = 0; i < direct.size(); i++) {
			int newX = current.x + direct[i][0];
			int newY = current.y + direct[i][1];

			
			if (0 <= newX && newX < n && 0 <= newY && newY < n
			&& !visited[newX][newY]) {
				visited[newX][newY] = true;
				if (spaces[newX][newY] == 0 || spaces[newX][newY] == sharkSize) {
					routes.push(Node(newX, newY, current.count+1));
				} else if (spaces[newX][newY] < sharkSize) {
					if (find) {
						if (returnCount < current.count) {
							spaces[sharkX][sharkY] = 0;
							return returnCount+1;
						}
						if (sharkX > newX || (sharkX == newX && sharkY > newY)) {
							sharkX = newX;
							sharkY = newY;
						}
					} else {
						sharkX = newX;
						sharkY = newY;
					}
					find = true;
					returnCount = current.count;
				}
			}
		}
	}

	if (find) {
		spaces[sharkX][sharkY] = 0;
		return returnCount+1;
	}

	return 0;
}

int main() {
    // freopen("input.txt", "r", stdin);

	sharkSize = 2;
	cin >> n;
	spaces.resize(n);
	for (int i = 0; i < n; i++) {
		spaces[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> spaces[i][j];
			if (spaces[i][j] == 9) {
				sharkX = i;
				sharkY = j;
				spaces[i][j] = 0;
			}
		}
	}

	int temp = -1, eat = 0;
	while (temp) {
		temp = gotoNearFish(sharkX, sharkY);
		eat++;
		if (eat == sharkSize) {
			eat = 0;
			sharkSize++;
		}
		answer += temp;
	}

	cout << answer << endl;
	

	return 0;
}