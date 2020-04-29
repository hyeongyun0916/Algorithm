#include <bits/stdc++.h>
using namespace std;

const int mod11693 = 1000000007;

map<int, int> getPrimeFactorization(int n) {
    map<int, int> primeFactorization;
    for (int i = 2; n != 1 && i*i <= n; i++) {
        if (!(n%i)) {
            n /= i;
            if (primeFactorization.find(i) == primeFactorization.end())
                primeFactorization.insert({i, 1});
            else
                primeFactorization[i]++;
            i--;
        }
    }
    if (n > 1)
        primeFactorization[n]++;
    return primeFactorization;
}

map<unsigned long long, unsigned long long> dp;
unsigned long long go(unsigned long long r, unsigned long long n) {
    if (n == 1) return dp[n] = r % mod11693;
    if (dp.find(n) != dp.end()) return dp[n] % mod11693;
    if(n%2 == 0) return dp[n] = ((go(r, n / 2)%mod11693)*(go(r, n / 2) % mod11693)) % mod11693;
    dp[n] = ((go(r, n / 2)%mod11693)*(go(r, n / 2) % mod11693)) % mod11693;
    return dp[n] = (dp[n]*(r%mod11693))%mod11693;
}

unsigned long long modGeometricSequence(int a, int alpha, int m) {
//    (a^(alpha*m)-1)/(a-1)
    long temp = (long)alpha*m+1;
    dp.clear();
    unsigned long long first = (go(a, temp)-1);
    dp.clear();
    unsigned long long second = (go(a-1, mod11693-2));
    return (first*second)%mod11693;
}

//acmicpc 11693
//n^m의 약수의 합
unsigned long long sumOfDivisor(int n, int m) {
    unsigned long long sum = 1;
    map<int, int> primeFactorization = getPrimeFactorization(n);
    for (auto& kv : primeFactorization) {
        unsigned long long temp = modGeometricSequence(kv.first, kv.second, m)%mod11693;
        sum *= temp;
        sum %= mod11693;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << sumOfDivisor(n, m) << endl;
}