#include <bits/stdc++.h>
using namespace std;

/*
dp로 푸는 방법이 있을 것 같은데..

일단 높이가 높은순부터 상하좌우에서
해당 높이까지 올 수 있는 경우의수를
더하면서 문제를 해결.
*/

struct Node {
    int value;
    int x;
    int y;
    Node(int _value, int _x, int _y)
     : value(_value), x(_x), y(_y) {}
    bool operator < (const Node &rhs) const {
        return tie(value) < tie(rhs.value);
	}
    bool operator > (const Node &rhs) const {
        return tie(value) > tie(rhs.value);
	}
};


vector<vector<int>> heights;
vector<vector<int>> routes;
vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
priority_queue<Node> positions;

// int answer;


int main() {
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    heights.resize(n);
    routes.resize(n);

    for (int i = 0; i < n; i++) {
        heights[i].resize(m);
        routes[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> heights[i][j];
            positions.push(Node(heights[i][j], i, j));
        }
    }

    // while (!positions.empty()) {
    //     cout << positions.top().value << endl;
    //     positions.pop();
    // }

    routes[0][0] = 1;
    while (!positions.empty()) {
        Node temp = positions.top();
        positions.pop();

        for (int i = 0; i < directions.size(); i++) {
            int newX = temp.x+directions[i][0];
            int newY = temp.y+directions[i][1];

            if (newX>=0 && newX<n && newY>=0 && newY<m) {
                if (heights[newX][newY]>temp.value) {
                    routes[temp.x][temp.y] += routes[newX][newY];
                }
            }
        }
    }

    cout << routes[n-1][m-1] << endl;
    // findRoute(0,0);
    // cout << answer << endl;

    return 0;
}