#include <bits/stdc++.h>

using namespace std;

int calculateWithoutBrace(vector<char> &s)
{
    int ret = 0;
    while (!s.empty())
    {
        int tempNum = 0;
        bool isPlus = true;
        bool isSign = false;
        if (s[0] == '-')
        {
            isPlus = false;
            isSign = true;
        }
        else if (s[0] == '+')
        {
            isSign =
        }
    }
    return ret;
}

int calculate(string s)
{
    vector<char> braceLeft, braceRight;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] == ')')
        {
            while (braceLeft.back() != '(')
            {
                braceRight.insert(braceRight.begin(), braceLeft.back());
                braceLeft.pop_back();
            }
            string tempStr = to_string(calculateWithoutBrace(braceRight));
            for (int j = 0; j < tempStr.size(); j++)
            {
                braceLeft.push_back(tempStr[j]);
            }
            continue;
        }
        braceLeft.push_back(s[i]);
    }

    return calculateWithoutBrace(braceLeft);
}

int main()
{
    string s = "1 + 1";
    s = "(1+(4-8+2)-3)+(6+8)";
    cout << calculate(s) << endl;
    return 0;
}