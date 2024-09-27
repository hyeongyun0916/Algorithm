#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> answer;
    int i = 0, j = 0, k = 0;
    bool move = false;
    while (answer.size() < matrix.size() * matrix[0].size())
    {
        for (; j < matrix[0].size() - k; j++)
        {
            answer.push_back(matrix[i][j]);
            move = true;
        }
        if (!move)
        {
            break;
        }
        i += 1;
        j -= 1;
        move = false;
        for (; i < matrix.size() - k; i++)
        {
            answer.push_back(matrix[i][j]);
            move = true;
        }
        if (!move)
        {
            break;
        }
        j -= 1;
        i -= 1;
        move = false;
        for (; j > -1 + k; j--)
        {
            answer.push_back(matrix[i][j]);
            move = true;
        }
        if (!move)
        {
            break;
        }
        i -= 1;
        k += 1;
        j += 1;
        move = false;
        for (; i > -1 + k; i--)
        {
            answer.push_back(matrix[i][j]);
            move = true;
        }
        if (!move)
        {
            break;
        }
        j += 1;
        i += 1;
        move = false;
    }
    return answer;
}

void printAns(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " " << endl;
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printAns(spiralOrder(matrix));

    return 0;
}