#
# @lc app=leetcode id=279 lang=python3
#
# [279] Perfect Squares
#

# @lc code=start

class Solution:
    def numSquares(self, n: int) -> int:
        if n == 1 or n == 2:
            return n
        dp = [10000] * (n+1)
        i = 1
        while i*i < n+1:
            dp[i*i] = 1
            i += 1
        dp[2] = 2
        for i in range(3, n+1):
            if dp[i] == 1:
                continue
            j = 1
            while j*j <= i:
                dp[i] = min(dp[i], 1+dp[i-j*j])
                j += 1
            # for j in range(1, (i//2)+1):
            #     dp[i] = min(dp[i], dp[i-j]+dp[j])
            #     if dp[i] == 2:
            #         break
        return dp[n]


# @lc code=end

s = Solution()
print(s.numSquares(28))
