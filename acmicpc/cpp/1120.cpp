#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    string a, b;
    cin >> a >> b;
    int minDiff = 987654321;
    for (int i = 0; i < b.size() - a.size() +1; i++) {
        int tempDiff = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[j+i]) tempDiff++;
        }
        minDiff = min(minDiff, tempDiff);
    }
    cout << minDiff << endl;
    return 0;
}