#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charSet.count(s[right]) == 0)
            {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            }
            else
            {
                while (charSet.count(s[right]))
                {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLength;
    }
};
// @lc code=end

int main()
{
    Solution s;
    string str = "pwwkew";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}