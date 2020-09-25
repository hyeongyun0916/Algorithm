#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int repeat = pow(num, 0.5)+1;
        int count = 0;
        for (int j = 1; j < repeat; j++) {
            if (!(num%j)) {
                count+=2;
            }
        }
        repeat-=1;
        if (repeat*repeat == num)
            count--;
        cout << num << " " << count << endl;
    }
    
    return 0;
}