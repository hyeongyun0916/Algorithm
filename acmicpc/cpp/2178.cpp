#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> direct = {{-1,0}, {0,-1}, {1,0}, {0,1}};
vector<string> maze;
int n, m;

struct Node {
    int x;
    int y;
	int count;
    Node(int _x, int _y, int _count)
     : x(_x), y(_y), count(_count) {}
};

int main() {
    //freopen("input.txt", "r", stdin);
	cin >> n >> m;

	maze.resize(n);
	for (int i = 0; i < n; i++) cin >> maze[i];

	queue<Node> q;
	maze[0][0] = '0';
	q.push(Node(0,0,1));

	while (!q.empty()) {
		Node front = q.front();
		q.pop();

		for (int i = 0; i < direct.size(); i++) {
			int x = front.x+direct[i][0];
			int y = front.y+direct[i][1];

			if (x==n-1 && y==m-1) {
				cout << front.count+1 << endl;
				return 0;
			} 

			if (0<=x && x<n && 0<=y && y<m) {
				if (maze[x][y] == '1') {
					maze[x][y] = '0';
					q.push(Node(x,y,front.count+1));
				}
			}
		}
	}
	

	return 0;
}