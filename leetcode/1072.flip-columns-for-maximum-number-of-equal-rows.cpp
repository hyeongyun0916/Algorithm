#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        map<string, int> answers;
        for (int i = 0; i < matrix.size(); i++)
        {
            string o, r;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                o += '0' + matrix[i][j];
                r += '1' - matrix[i][j];
            }
            answers[o] += 1;
            answers[r] += 1;
        }

        int answer = 0;
        for (pair<string, int> p : answers)
        {
            answer = max(answer, p.second);
        }

        return answer;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> m = {{1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1}};
    cout << s.maxEqualRowsAfterFlips(m) << endl;
    return 0;
}