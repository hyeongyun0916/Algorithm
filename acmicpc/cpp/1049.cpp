#include <bits/stdc++.h>
using namespace std;
  
int main() {
    // freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    int packageMin = 987654321, pieceMin = 987654321;
    while (M--) {
        int package, piece;
        cin >> package >> piece;
        packageMin = min(packageMin, package);
        pieceMin = min (pieceMin, piece);
    }
    int a = pieceMin*N;
    int b = packageMin*(N/6)+(N%6)*pieceMin;
    int c = ceil(N/6.f)*packageMin;
    cout << min(min(a, b), c) << endl;
    return 0;
}