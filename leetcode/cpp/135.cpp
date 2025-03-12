#include <bits/stdc++.h>

using namespace std;

int candy(vector<int> &ratings)
{
    vector<int> candys(max(2, (int)ratings.size()), 0);
    candys[0] = 0;
    candys[1] = 1;
    for (int i = 2; i < ratings.size(); i++)
    {
        candys[i] = candys[i - 1] + i;
    }
    if (ratings.size() == 1)
    {
        return 1;
    }
    vector<int> biggerThanNeighor(ratings.size(), 0);
    biggerThanNeighor[0] = ratings[0] > ratings[1] ? 2 : 0;
    biggerThanNeighor[ratings.size() - 1] = ratings[ratings.size() - 1] > ratings[ratings.size() - 2] ? 1 : 0;
    for (int i = 1; i < ratings.size() - 1; i++)
    {
        if ((ratings[i] > ratings[i - 1]) && (ratings[i] > ratings[i + 1]))
        {
            biggerThanNeighor[i] = 3;
        }
        else if (ratings[i] > ratings[i - 1])
        {
            biggerThanNeighor[i] = 1;
        }
        else if (ratings[i] > ratings[i + 1])
        {
            biggerThanNeighor[i] = 2;
        }
    }
    int answer = 0, before = 0, oneMax = 0, twoMax = 0;
    bool three = false;
    for (int i = 0; i < biggerThanNeighor.size(); i++)
    {
        switch (biggerThanNeighor[i])
        {
        case 0:
            answer += candys[oneMax];
            answer += candys[twoMax];
            if (three)
            {
                answer += max(oneMax, twoMax) + 1;
            }
            three = false;
            oneMax = 0;
            twoMax = 0;
            break;
        case 1:
            oneMax++;
            break;
        case 2:
            twoMax++;
            break;
        case 3:
            three = true;
            break;

        default:
            break;
        }
    }
    answer += candys[oneMax];
    answer += candys[twoMax];
    if (three)
    {
        answer += max(oneMax, twoMax) + 1;
    }
    return answer + ratings.size();
}

int main()
{
    vector<int> ratings1 = {1, 0, 1, 6, 10, 8, 7, 3, 2}; //{1, 2, 87, 87, 87, 2, 1};
    vector<int> ratings2 = {0, 1, 2, 3, 2, 1};
    vector<int> ratings3 = {1, 3, 4, 5, 2};

    cout << candy(ratings1) << endl;
    cout << candy(ratings2) << endl;
    cout << candy(ratings3) << endl;

    return 0;
}