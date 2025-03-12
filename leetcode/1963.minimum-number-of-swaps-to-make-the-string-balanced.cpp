#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
class Solution
{
public:
    int minSwaps(string s)
    {
        int ret = 0;
        int i = 0, j = s.size() - 1;
        int left = 0, right = 0;
        while (i < j)
        {
            for (; i < j && left >= 0; i++)
            {
                if (s[i] == '[')
                    left++;
                else
                    left--;
            }
            for (; i < j && right >= 0; j--)
            {
                if (s[j] == ']')
                    right++;
                else
                    right--;
            }
            if (i >= j)
            {
                if (left < 0)
                    ret++;
                break;
            }
            ret++;
            right += 2;
            left += 2;
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.minSwaps("]]][[[") << endl;
    return 0;
}