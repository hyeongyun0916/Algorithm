#include <bits/stdc++.h>
using namespace std;

/*
처음에 주어진 선택지에서 정해진 횟수로 자르려고 해서 문제가 어렵게 보였음
'내가 몇으로 자를껀데, 이게 정해진 횟수 이상이니?'로 문제를 바꾸면 쉬움

문제를 검색하다가 파라메트릭 서치라는 단어를 보았는데, 결국 이진 탐색

최댓값, 최솟값 문제에서는 이진탐색을 항상 고려해보자
*/


bool isPossible(vector<int> &arr, int size, int k) {
    int now = 0, cnt = 0;
    for (auto i : arr) {
        if (i-now >= size) {
            cnt++;
            now = i;
        }
    }
    return cnt > k;
}

int main() {
    // freopen("acmicpc/cpp/input.txt", "r", stdin);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i];
    arr.push_back(l);
    while (n--) {
        int k;
        cin >> k;
        
        int low = 0, high = l;
        while (low+1 < high) {
            int mid = (int)((low+high)/2);
            if (isPossible(arr, mid, k)) low = mid;
            else high = mid;
        }        
        cout << low << endl;
    }
    
    return 0;
}