#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll f1 = 0, f2 = 1;
    for (ll i = 0; i < n; i++) {
        if (i%2) {
            f1 += f2;
        } else {
            f2 += f1;
        }
    }
    
    cout << ((n%2) ? f2 : f1) << endl;

    return 0;
}