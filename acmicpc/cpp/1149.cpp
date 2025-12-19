#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> price(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }
    vector<vector<int>> lowSumPrice(n, vector<int>(3, 0));
    lowSumPrice[n - 1][0] = price[n - 1][0];
    lowSumPrice[n - 1][1] = price[n - 1][1];
    lowSumPrice[n - 1][2] = price[n - 1][2];
    for (int i = n - 2; i >= 0; i--)
    {
        lowSumPrice[i][0] = price[i][0] + min(lowSumPrice[i + 1][1], lowSumPrice[i + 1][2]);
        lowSumPrice[i][1] = price[i][1] + min(lowSumPrice[i + 1][0], lowSumPrice[i + 1][2]);
        lowSumPrice[i][2] = price[i][2] + min(lowSumPrice[i + 1][0], lowSumPrice[i + 1][1]);
    }
    cout << min(min(lowSumPrice[0][0], lowSumPrice[0][1]), lowSumPrice[0][2]) << endl;
    return 0;
}