#include <bits/stdc++.h>
using namespace std;

int n, m;

bool checkBound(int a, int b, int c, int d, int e, int f) {
    return 0 <= a && a < n && 0 <= b && b < m
        && 0 <= c && c < n && 0 <= d && d < m
        && 0 <= e && e < n && 0 <= f && f < m;
}

int countBoardCover(char **chMap, int x, int y, int nDot) {
    if (nDot == 0) {
        return 1;
    }

    int ret = 0;
    
    int a, b, c, d, e, f;


    // case 1: ㄱ모양
    a = x;
    b = y;
    c = x;
    d = y+1;
    e = x+1;
    f = y+1;
    
    if (checkBound(a, b, c, d, e, f)
        && chMap[a][b] == '.' && chMap[c][d] == '.' && chMap[e][f] == '.'  ) {
        if (nDot == 3)
            return 1;
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '#';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i>x || j>y) && chMap[i][j] == '.') {
                    ret += countBoardCover(chMap, i, j, nDot-3);
                }
            }
        }
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '.';
    }
    
    // case 2: ㄱ을 시계 반대방향으로 90도
    a = x;
    b = y;
    c = x;
    d = y+1;
    e = x+1;
    f = y;
    
    if (checkBound(a, b, c, d, e, f)
        && chMap[a][b] == '.' && chMap[c][d] == '.' && chMap[e][f] == '.'  ) {
        if (nDot == 3)
            return 1;
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '#';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i>x || j>y) && chMap[i][j] == '.') {
                    ret += countBoardCover(chMap, i, j, nDot-3);
                }
            }
        }
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '.';
    }
    
    // case 3: ㄱ을 시계 반대방향으로 180도 (ㄴ 모양)
    a = x;
    b = y;
    c = x+1;
    d = y;
    e = x+1;
    f = y+1;
    
    if (checkBound(a, b, c, d, e, f)
        && chMap[a][b] == '.' && chMap[c][d] == '.' && chMap[e][f] == '.'  ) {
        if (nDot == 3)
            return 1;
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '#';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i>x || j>y) && chMap[i][j] == '.') {
                    ret += countBoardCover(chMap, i, j, nDot-3);
                }
            }
        }
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '.';
    }
    
    // case 4: ㄱ을 시계 반대방향으로 270도
    a = x;
    b = y;
    c = x+1;
    d = y;
    e = x+1;
    f = y-1;
    
    if (checkBound(a, b, c, d, e, f)
        && chMap[a][b] == '.' && chMap[c][d] == '.' && chMap[e][f] == '.'  ) {
        if (nDot == 3)
            return 1;
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '#';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i>x || j>y) && chMap[i][j] == '.') {
                    ret += countBoardCover(chMap, i, j, nDot-3);
                }
            }
        }
        chMap[a][b] = chMap[c][d] = chMap[e][f] = '.';
    }

    return ret;
}

// https://www.algospot.com/judge/problem/read/BOARDCOVER

/* 
    실패한 코드.
    종만북을 보고 고칠 점
    1. for이 군데군데 있으면, 왼쪽위부터 시작한다는 보장이 없음.
    2. x축과 y축이 계속 헷갈리므로 y = i로 두는 것이 좋을 듯.
    3. 4가지 케이스를 배열로 합치기
*/

int main() {
    freopen("ALGOSPOT_JONGMANBOOK/input.txt", "r", stdin);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int nDot = 0;
        cin >> n >> m;
        char** chMap = new char*[n];
        for (int j = 0; j < n; j++) {
            chMap[j] = new char[m];
            for (int k = 0; k < m; k++) {
                cin >> chMap[j][k];
                if (chMap[j][k] == '.')
                    nDot += 1;
            }
        }

        int answer = 0;
        if (nDot % 3) cout << 0 << endl;
        else {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (chMap[j][k] == '.') {
                        answer += countBoardCover(chMap, j, k, nDot);
                    }
                }
            }
            cout << answer << endl;
        }
    }

    return 0;
}