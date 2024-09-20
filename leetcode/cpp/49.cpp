#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (auto x : strs)
    {
        string word = x;
        sort(word.begin(), word.end());
        mp[word].push_back(x);
    }

    vector<vector<string>> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}

void printAns(vector<vector<string>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " " << endl;
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; i++)
    {
        string tempStr;
        cin >> tempStr;
        strs.push_back(tempStr);
    }
    printAns(groupAnagrams(strs));
    return 0;
}