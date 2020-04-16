#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

vector<string> board;

bool inRange(int y, int x) {
    return -1<x&&x<6 && -1<y&&y<6;
}

bool hasWord(int y, int x, const string& word) {
    if (!inRange(y,x)) return false;

    if (board[y][x] != word[0]) return false;

    if (word.size() == 1) return true;

    for (int direction = 0; direction < 8; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}

void solve() {
    board.clear();
    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        board.push_back(str);
    }

    int cnt;
    cin >> cnt;
    for (int t = 0; t < cnt; t++) {
        string str;
        cin >> str;
        
        bool find = false;
        for (int i = 0; i < 5 && !find; i++) {
            for (int j = 0; j < 5 && !find; j++) {
                if (hasWord(i, j, str))
                    find = true;
            }
        }
        if (find)
            cout << str << " YES" << endl;
        else
            cout << str << " NO" << endl;
    }
}


// https://www.algospot.com/judge/problem/read/BOGGLE
int main() {
    freopen("ALGOSPOT_JONGMANBOOK/input.txt", "r", stdin);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        solve();
    }
    return 0;
}