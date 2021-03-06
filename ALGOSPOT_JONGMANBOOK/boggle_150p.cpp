#include <bits/stdc++.h>
using namespace std;

// 해당 문제는 dp로 풀어야함.
// 150p에서는 완전 탐색이므로 해결방법은 아님.

// 주어진 문자열 맵에서 단어 찾기. 이동할수 있는 범위는 팔방

vector<vector<int>> direct = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1},
};

// 2. 두번째 이후 글자를 찾는다.
bool findNext(const vector<string>& strMap, string str, int pos, int i, int j) {
    if (str.size() == pos)
        return true;
    for (int d = 0; d < direct.size(); d++) {
        int x = i+direct[d][0], y = j+direct[d][1];
        // 종만북에서는 범위판단을 시작할 때 놓음 -> 재귀함수는 두군데 이상에서 호출되기 떄문에
        if (-1<x&&x<6 && -1<y&&y<6 && strMap[x][y] == str[pos])
            if (findNext(strMap, str, pos+1, x, y))
                return true;
    }
    return false;
}

// 1. 첫 글자를 찾고
string findFirst(const vector<string>& strMap, string str) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (strMap[i][j] == str[0]) {
                if (findNext(strMap, str, 1, i ,j))
                    return "YES";
            }
        }
    }
    return "NO";
}

void solve() {
    vector<string> strMap;
    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        strMap.push_back(str);
    }

    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        string str;
        cin >> str;
        cout << str << " " << findFirst(strMap, str) << endl;
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