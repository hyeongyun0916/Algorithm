#include <bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    if (triangle.size() == 1)
        return triangle[0][0];
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

// void printAns(vector<vector<string>> ans)
// {
//     for (int i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout << ans[i][j] << " " << endl;
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}