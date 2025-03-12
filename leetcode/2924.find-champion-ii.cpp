#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]][edges[i][1]] = 1;
        }
        vector<bool> winner(n, true);
        queue<int> nodes;
        for (int i = 0; i < n; i++)
        {
            if (winner[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (winner[j] && graph[i][j])
                    {
                        nodes.push(j);
                    }
                }
                while (!nodes.empty())
                {
                    int k = nodes.front();
                    nodes.pop();
                    winner[k] = false;
                    for (int j = 0; j < n; j++)
                    {
                        if (winner[j] && graph[k][j])
                        {
                            nodes.push(j);
                        }
                    }
                }
            }
        }
        int answer = -1;
        for (int i = 0; i < n; i++)
        {
            if (winner[i])
            {
                if (answer == -1)
                    answer = i;
                else
                    return -1;
            }
        }
        return answer;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};
    cout << s.findChampion(4, edges) << endl;
    return 0;
}