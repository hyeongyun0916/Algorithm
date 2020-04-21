#include <bits/stdc++.h>
using namespace std;


// 순서대로 내 코드 case의 2, 1, 3, 4
const int coverType[4][3][2] = {
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {1, 0}, {1, -1} },
};
bool setBoard(vector<vector<int>>& board, int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= board.size() 
            || nx < 0 || nx >= board[0].size())
                ok = false;
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>>& board) {
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (x != -1) break;
    }

    if (x == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; ++type) {
        if (setBoard(board, y, x, type, 1))
            ret += cover(board);
        setBoard(board, y, x, type, -1);
    }
    return ret;
}

// https://www.algospot.com/judge/problem/read/BOARDCOVER

int main() {
    freopen("ALGOSPOT_JONGMANBOOK/input.txt", "r", stdin);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> board;
        for (int j = 0; j < n; j++) {
            vector<int> temp;
            for (int k = 0; k < m; k++) {
                char ch;
                cin >> ch;
                if (ch == '.') temp.push_back(0);
                else temp.push_back(1);
            }
            board.push_back(temp);
        }

        cout << cover(board) << endl;
    }

    return 0;
}