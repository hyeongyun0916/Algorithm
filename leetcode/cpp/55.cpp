#include <bits/stdc++.h>

using namespace std;

bool jump(vector<int> &nums, int pos)
{
    if (pos == nums.size() - 1)
    {
        return true;
    }
    int n = nums[pos];
    nums[pos] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (jump(nums, pos + i))
        {
            return true;
        }
    }
    return false;
}

bool canJump(vector<int> &nums)
{
    return jump(nums, 0);
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << endl;

    return 0;
}