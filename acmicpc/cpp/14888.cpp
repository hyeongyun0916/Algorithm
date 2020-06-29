#include <iostream>
using namespace std;

int *expArr;
int expMax;
int expMin;

void calculateExp(char* set, int set_size) {
    int result = expArr[0];
    for (int i = 0; i < set_size; i++) {
        switch (set[i]) {
            case '+':
                result += expArr[i+1];
                break;
            case '-':
                result -= expArr[i+1];
                break;
            case '*':
                result *= expArr[i+1];
                break;
            case '/':
                result /= expArr[i+1];
                break;
            default:
                break;
        }
    }
    expMax = max(expMax, result);
    expMin = min(expMin, result);
}

void expressionPerm(char* set, int set_size, int m, int n) {
    if (set_size == n) {
//        Print_set(set, set_size);
        calculateExp(set, set_size);
        return;
    }
    for (int i = set_size; i < m; i++) {
        swap(set[i], set[set_size]);
        expressionPerm(set, set_size+1, m, n);
        swap(set[i], set[set_size]);
    }
}

void expression() {
    int n;
    cin >> n;
    
    expMax = -987654321;
    expMin = 987654321;
    
    expArr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> expArr[i];
    }
    int plus, minus, multi, division;
    cin >> plus >> minus >> multi >> division;
    char *exp = new char[plus+minus+multi+division];
    for (int i = 0; i < plus; i++)
        exp[i] = '+';
    for (int i = plus; i < plus+minus; i++)
        exp[i] = '-';
    for (int i = plus+minus; i < plus+minus+multi; i++)
        exp[i] = '*';
    for (int i = plus+minus+multi; i < plus+minus+multi+division; i++)
        exp[i] = '/';

    
    expressionPerm(exp, 0, plus+minus+multi+division, plus+minus+multi+division);
    cout << expMax << endl << expMin << endl;
}

int main() {
    expression();
    return 0;
}