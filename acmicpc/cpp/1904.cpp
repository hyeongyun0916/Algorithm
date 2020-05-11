#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
00 => b, 1 => a로 치환해서 생각한다면
만약 n=5라고 했을때
abb / aaab / aaaaa 라고 생각 할 수 있음.
이라고 생각해서 다음 주석과 같이 작성했다가, 
n > m 일 때, fact[n] < fact[m]가 더 큰 케이스 등이 있을 수 있음

결과적으로 피보나치 수열이길래 피보나치로 작성해서 제출

vector<ll> fact;

ll getFact(ll n) {
    if (fact[n]) {
        return fact[n];
    }

    fact[n] = (n * getFact(n-1))%15746;
    return fact[n];
}

int main() {
    // while (true) {
    ll n, answer = 0;
    cin >> n;

    fact.resize(n+1);
    fact[0] = 1;
    getFact(n);
    for (ll i = 0; i*2 <= n; i++) {
        answer += fact[n-i]/fact[n-i-i]/fact[i];
    }
    cout << answer << endl;
    // }
    return 0;
}

*/

int main() {
    ll n;
    cin >> n;

    n += 1;
    
    ll f1 = 0, f2 = 1;
    for (ll i = 0; i < n; i++) {
        if (i%2) {
            f1 += f2;
            f1 %= 15746;
        } else {
            f2 += f1;
            f2 %= 15746;
        }
    }
    
    cout << ((n%2) ? f2 : f1)%15746 << endl;

    return 0;
}