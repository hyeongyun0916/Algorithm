#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        distance[0][0] = grid[0][0];
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (auto [dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    int newDist = distance[x][y] + grid[nx][ny];
                    if (distance[nx][ny] > newDist)
                    {
                        distance[nx][ny] = newDist;
                        if (grid[nx][ny] == 0)
                        {
                            dq.push_front({nx, ny});
                        }
                        else
                        {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        return distance[m - 1][n - 1];
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << s.minimumObstacles(grid) << endl;
    return 0;
}