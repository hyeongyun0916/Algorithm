#include <iostream>
using namespace std;

bool isDouble(double f) {
    return (f-(int)f != 0);
}

int cainCalendar(int M, int N, int x, int y) {
    if (M == N) {
        if (x == y) {
            return x;
        }
        else {
            return -1;
        }
    }
    
    if (M < N) {
        int tempN = M, tempY = x;
        M = N;
        x = y;
        N = tempN;
        y = tempY;
    }
    
    for (int a = 0; a <= M; a++) {
        double b = (double)(M*a + x - y)/N;
        if (isDouble(b)) {
            continue;
        }
        return M*a+x;
    }
    return -1;
}

int main() {
    int t = 0;
    
    cin >> t;
    
    
    for(int i = 0; i < t; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << cainCalendar(M, N, x, y) << endl;
    }
    
    return 0;
}