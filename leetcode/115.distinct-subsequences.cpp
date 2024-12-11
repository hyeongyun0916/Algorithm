#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        if (s.size() < t.size())
            return 0;
        vector<vector<double>> m(t.size(), vector<double>(s.size(), 0));
        m[0][0] = t[0] == s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (t[0] == s[i])
                m[0][i] = m[0][i - 1] + 1;
            else
                m[0][i] = m[0][i - 1];
        }

        for (int i = 1; i < t.size(); i++)
        {
            for (int j = 1; j < s.size(); j++)
            {
                if (t[i] == s[j])
                {
                    m[i][j] = m[i][j - 1] + m[i - 1][j - 1];
                }
                else
                {
                    m[i][j] = m[i][j - 1];
                }
            }
        }

        return m[t.size() - 1][s.size() - 1];
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.numDistinct("babgbag", "bag") << endl;
    return 0;
}