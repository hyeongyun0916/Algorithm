#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v0, v1;

ll getFibo0(ll n) {
    // if (n <= 1) {
    //     v0[n] = n;
    //     return n;
    // }

    if (v0[n] || n <= 1) {
        return v0[n];
    }

    v0[n] = getFibo0(n-1) + getFibo0(n-2);
    return v0[n];
}

ll getFibo1(ll n) {
    // if (n <= 1) {
    //     v1[n] = n;
    //     return n;
    // }

    if (v1[n] || n <= 1) {
        return v1[n];
    }

    v1[n] = getFibo1(n-1) + getFibo1(n-2);
    return v1[n];
}

int main() {
    ll t;
    cin >> t;
    v0.resize(41);
    v1.resize(41);
    v0[0] = v1[1] = 1;
    getFibo0(40);
    getFibo1(40);
    while (t--)
    {
        ll n;
        cin >> n;
        /*
        if (n+1 > v0.size()) {
            v0.resize(n+1);
            v1.resize(n+1);
        }
        */
        cout << v0[n] << ' ' << v1[n] << endl;
    }
    
    return 0;
}