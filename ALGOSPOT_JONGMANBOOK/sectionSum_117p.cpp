#include <bits/stdc++.h>
using namespace std;

const int MIN = numeric_limits<int>::min();

int myAnswer(const vector<int>& A) {
    int N = A.size(), ret = MIN;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            ret = max(ret, sum);
        }
    }

    return ret;
}

int fastMaxSum(const vector<int>& A, int lo, int hi) {
    if (lo == hi) return A[lo];

    int mid = (lo+hi)/2;

    int left = MIN, right = MIN, sum = 0;

    // i ~ mid ~ j 까지 최대 합
    for (int i = mid; i >= lo; i--) {
        sum += A[i];
        left = max(left, sum);
    }
    sum = 0;
    for (int j = mid+1; j <= hi; j++) {
        sum += A[j];
        right = max(right, sum);
    }

    // 왼쪽 오른쪽 구간 중 큰 값
    int single = max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid+1, hi));

    return max(left+right, single);
}

int fastestMaxSum(const vector<int>& A) {
    // psum은 이전까지의 합이 마이너스가 되었을때 새로운 스타트가 될 수 있는 지점(이전까지의 합이 마이너스면 새로 시작하는게 이득)부터 i까지의 합
    // ret은 max
    int N = A.size(), ret = MIN, psum = 0;
    for (int i = 0; i < N; i++) {
        psum = max(psum, 0) + A[i];
        ret = max(psum, ret);
    }
    return ret;
}

int main() {
    // vector<int> temp = {-7, 4, -3, 6, 3, -8, 3, 4};
    vector<int> temp = {-7, -6, -8, -5};
    cout << fastestMaxSum(temp) << endl;
    return 0;
}