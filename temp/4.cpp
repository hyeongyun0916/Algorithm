

#include <bits/stdc++.h>

using namespace std;

long get_operation_number(vector<long> A)
{
    long maxValue = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        maxValue = max(maxValue, A[i]);
    }
    long answer = 0;
    long maxNeed = 0;
    long sectionMax = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (sectionMax < A[i])
        {
            sectionMax = A[i];
            maxNeed = max(maxNeed, maxValue - A[i]);
        }
        else
        {
            answer += maxNeed;
            sectionMax = A[i];
            maxNeed = max((long)0, maxValue - A[i]);
        }
    }
    return answer + maxNeed;
}

int main()
{
    // cout << get_operation_number({1, 1, 4, 2}) << endl; // 5
    cout << get_operation_number({1, 2, 4, 3, 1, 3, 2, 2, 5}) << endl;
    // cout << get_operation_number({1, 2, 4, 3, 1, 3, 2,  2, 5, 2}) << endl;
    return 0;
}