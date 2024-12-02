#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        s = ' ' + s;
        p = ' ' + p;
        vector<vector<bool>> dp(s.size(), vector<bool>(p.size(), false));
        dp[0][0] = true;

        for (int j = 1; j < p.size(); j++)
        {
            for (int i = 0; i < s.size(); i++)
            {
                bool already = false;
                if (p[j] == '*' && dp[i][j - 1])
                    for (; i < s.size(); i++)
                    {
                        dp[i][j] = true;
                        already = true;
                    }
                if (already || i == 0 || !dp[i - 1][j - 1])
                    continue;
                else if (p[j] == '?')
                    dp[i][j] = true;
                else
                    dp[i][j] = s[i] == p[j];
            }
        }

        return dp[s.size() - 1][p.size() - 1];
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.isMatch("mississippi", "m??*ss*?i*pi") << endl;
    return 0;
}