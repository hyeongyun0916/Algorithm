#include <bits/stdc++.h>
using namespace std;


//  ┐└ ┘┌  
vector<vector<vector<int>>> tetrominos = {
	{{0,0}, {0,1}, {0,2}, {0,3}},	// ㅡ
	{{0,0}, {1,0}, {2,0}, {3,0}},	// ㅣ
	{{0,0}, {0,1}, {1,0}, {1,1}},	// ㅁ
	{{0,0}, {1,0}, {2,0}, {2,1}},	// └
	{{0,0}, {0,1}, {0,2}, {-1,2}},	// --┘
	{{0,0}, {0,1}, {1,1}, {2,1}},	// ┐
	{{0,0}, {0,1}, {0,2}, {1,0}},	// ┌--
	{{0,0}, {0,1}, {-1,1}, {-2,1}},	// ┘
	{{0,0}, {0,1}, {0,2}, {1,2}},	// --┐
	{{0,0}, {0,1}, {1,0}, {2,0}},	// ┌
	{{0,0}, {1,0}, {1,1}, {1,2}},	// └--
	{{0,0}, {1,0}, {1,1}, {2,1}},	// └┐
	{{0,0}, {0,1}, {-1,1}, {-1,2}},	// ┘┌
	{{0,0}, {0,1}, {1,1}, {1,2}},	// ┐└
	{{0,0}, {1,0}, {1,-1}, {2,-1}},	// ┌┘
	{{0,0}, {0,1}, {-1,1}, {0,2}},	// ㅗ
	{{0,0}, {1,0}, {1,1}, {2,0}},	// ㅏ
	{{0,0}, {0,1}, {1,1}, {0,2}},	// ㅜ
	{{0,0}, {0,1}, {-1,1}, {1,1}},	// ㅓ
};

void verify() {
	for (auto tetromino : tetrominos) {
		vector<vector<int>> map(10, vector<int>(10, 0));

		for (auto point: tetromino) {
			map[4+point[0]][4+point[1]] = 1;
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m));

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> paper[i][j];

	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				int x0 = i+tetrominos[k][0][0], y0 = j+tetrominos[k][0][1],
				x1 = i+tetrominos[k][1][0], y1 = j+tetrominos[k][1][1],
				x2 = i+tetrominos[k][2][0], y2 = j+tetrominos[k][2][1],
				x3 = i+tetrominos[k][3][0], y3 = j+tetrominos[k][3][1];

				if (0 <= x0 && x0 < n && 0 <= y0 && y0 < m
				&& 0 <= x1 && x1 < n && 0 <= y1 && y1 < m
				&& 0 <= x2 && x2 < n && 0 <= y2 && y2 < m
				&& 0 <= x3 && x3 < n && 0 <= y3 && y3 < m) {
					 maxValue = max(maxValue, paper[x0][y0] + paper[x1][y1]
					 + paper[x2][y2] + paper[x3][y3]);
				}
			}
		}
	}

	cout << maxValue << endl;

	return 0;
}