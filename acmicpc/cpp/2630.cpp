#include <bits/stdc++.h>
using namespace std;


int blue, white;

vector<vector<int>> colors;

int getColor(int x, int y, int size) {

    if (size == 1) {
        colors[x][y] ? blue++ : white++;
        return colors[x][y];
    }

    int a = getColor(x, y, size/2);
    int b = getColor(x+size/2, y, size/2);
    int c = getColor(x, y+size/2, size/2);
    int d = getColor(x+size/2, y+size/2, size/2);

    int color = -1;

    if (a == b && b == c && c == d) {
        if (a == 1) {
            blue -= 3;
            color = 1;
        } else if (a == 0) {
            white -= 3;
            color = 0;
        }
    }

    return color;
}

 
int main() {
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    colors.resize(n);
    for (int i = 0; i < n; i ++) {
        colors[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> colors[i][j];
        }
    }
    getColor(0,0,n);
    cout << white << endl << blue;
    return 0;
}