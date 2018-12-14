#include <bits/stdc++.h>
using namespace std;

const int limit = 1000000;
bool check[limit];
int prime[limit];
int pn;

void makePrime() {
	check[0] = true;
	check[1] = true;
	for (int i = 2; i < limit; i++) {
        if (!check[i]) {
            //check[i] = true;
            prime[pn++] = i;
            for (int j = i+i; j < limit; j+=i)
                check[j] = true;
        }
    }
}

void countFermat(int L, int U) {
    int nPrime = 0, nFermat = 0;
    for (int i = 0; i < pn; i++) {
        if (L<=prime[i] && prime[i]<=U) {
            nPrime++;
            if (prime[i]%4 == 1 || prime[i] == 2)
                nFermat++;
        }
    }
    cout << L << " " << U << " " << nPrime << " " << nFermat << endl;
}

int main() {
    makePrime();
    int L, U;
    cin >> L >> U;
    while (L != -1 || U != -1) {
        countFermat(L, U);
        cin >> L >> U;
    }
    return 0;
}