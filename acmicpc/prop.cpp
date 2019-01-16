#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

// 7881

/* factorial을 모두 구하는 것은 무리일 것 같음.
규칙을 찾아보고자 함.
n = 1 .... 일 때
답*반복횟수
0*1
1*2
2*4
3*2
4*2
5*6
6*2
7*2
8*2
9*6
10*2
11*2
12*6
...
규칙을 찾지 못함...
*/



long long *facotial;

int main() {
    int k = 3*pow(10, 6.0)+6;
    facotial = new long long[k];
    memset(facotial, 0, sizeof(facotial) * k);

    facotial[0] = 1;
    for(int i = 1; i < k; i++) {
        facotial[i] = i * facotial[i-1];
        cout << facotial[i] << endl;
        if (!facotial[i]) {
            cout << "0 " << i << endl;
            break;
        }
    }
    // cout << facotial[k-1] << endl;
    return 0;
}