// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem2.h"
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// @lc code=start
/**
 * Definition for singly-linked list.
 */

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *start = new ListNode();
        ListNode *cur = start;
        // ListNode *before = cur;
        int one, two, carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            if (l1 == nullptr)
            {
                one = 0;
            }
            else
            {
                one = l1->val;
                l1 = l1->next;
            }
            if (l2 == nullptr)
            {
                two = 0;
            }
            else
            {
                two = l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = (one + two + carry) % 10;
            carry = (one + two + carry) / 10;
            // before = cur;
        }
        // if (temp == 1)
        // {
        //     before->next = new ListNode();
        //     before->next->val = temp;
        // }
        // else if (before != cur)
        // {
        //     before->next = nullptr;
        // }
        ListNode *ans = start->next;
        delete start;
        // delete cur;
        // delete before;
        return ans;
    }
};
// @lc code=end

// int main()
// {
//     Solution s;
//     ListNode *l1 = new ListNode(9, new ListNode(9));
//     ListNode *l2 = new ListNode(9);
//     ListNode *ans = s.addTwoNumbers(l1, l2);
// }