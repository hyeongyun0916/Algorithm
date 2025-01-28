#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    vector<pair<int, int>> projects;
    for (int i = 0; i < profits.size(); i++)
    {
        projects.push_back(pair<int, int>{capital[i], profits[i]});
    }
    sort(projects.begin(), projects.end(), compare);

    priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        for (; j < projects.size() && projects[j].first <= w; j++)
        {
            pq.push(projects[j].second);
        }
        if (pq.empty())
            break;
        w += pq.top();
        pq.pop();
    }

    return w;
}

int main()
{
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {1, 1, 2};
    int k = 1, w = 0;
    cout << findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}