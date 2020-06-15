#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v(101);

int main() {
    int t, n;
    cin >> t;
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 2;
    v[5] = 2;
    auto size = 6;
    for (auto i = size; i < v.size(); i++) {
        v[i] = v[i-1] + v[i-5];
    }
    while (t--) {
        cin >> n;
        cout << v[n] << endl;
    }
    

    return 0;
}