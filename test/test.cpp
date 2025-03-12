#include <bits/stdc++.h>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    vector<vector<int>> square(n, vector<int>(n, 0));
    r_q--;
    c_q--;
    for (int i = 0; i < k; i++)
    {
        int r = obstacles[i][0] - 1;
        int c = obstacles[i][1] - 1;
        if (r >= 0 && r < n && c >= 0 && c < n)
            square[obstacles[i][0] - 1][obstacles[i][1] - 1] = 1;
    }
    int answer = 0;
    vector<vector<int>> dir = {
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
        {-1, -1},
    };
    for (int d = 0; d < dir.size(); d++)
    {
        int r = r_q + dir[d][0], c = c_q + dir[d][1];
        while (r >= 0 && r < n && c >= 0 && c < n && square[r][c] == 0)
        {
            answer++;
            r += dir[d][0];
            c += dir[d][1];
        }
    }
    return answer;
}

int main()
{
    cout << queensAttack(4, 0, 4, 4, {}) << endl;
    cout << queensAttack(5, 3, 4, 3, {{5, 5}, {4, 2}, {2, 3}}) << endl;
    return 0;
}