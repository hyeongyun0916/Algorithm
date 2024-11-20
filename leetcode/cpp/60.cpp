#include <bits/stdc++.h>

using namespace std;

string getPermutation(int n, int k)
{
    // make a permutation of 1 to n
    string s;
    for (int i = 0; i < n; i++)
    {
        s.push_back(i + '1');
    }
    if (k == 1)
    {
        return s;
    }

    /*
        1234
        1243
        1324
        1342
        1423
        1432
        2134
        2143
        2314
        2341
    */

    for (int i = 1; i < k; i++)
    {
        int j = n - 2;
        while (j >= 0 && s[j] >= s[j + 1])
        {
            j--;
        }
        if (j < 0)
        {
            break;
        }
        int l = n - 1;
        while (s[j] >= s[l])
        {
            l--;
        }
        swap(s[j], s[l]);
        reverse(s.begin() + j + 1, s.end());
        cout << s << endl;
    }
    return s;
}

int main()
{
    cout << getPermutation(4, 10) << endl;

    return 0;
}