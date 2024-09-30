#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    long long ret = 0, i = 0, lenS = s.size(), sign = 1;
    for (; i < lenS; i++)
    {
        if (s[i] != ' ')
            break;
    }
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    if (s[i] == '+')
    {
        i++;
    }
    for (; i < lenS; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            break;
        if (sign == 1)
            ret = ret * 10 + (s[i] - '0');
        else
            ret = ret * 10 - (s[i] - '0');
        if (sign == -1 && ret > 0)
            ret *= -1;
        if (ret >= INT32_MAX)
            ret = INT32_MAX;
        else if (ret <= INT32_MIN)
            ret = INT32_MIN;
    }
    return ret;
}

int main()
{
    string s = "91283472332";
    cout << myAtoi(s) << endl;
    return 0;
}