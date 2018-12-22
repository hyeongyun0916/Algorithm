#include <iostream>
#include <vector>
using namespace std;

int lineUp(vector<int> line) {
    vector<int> pos(line.size());
    for (int i = 0; i < line.size(); i++) {
        pos[line[i]-1] = i;
    }
    int maxCount = 1;
    int count = 1;
    for (int i = (int)pos.size() -2; i >= 0; i--) {
        if (pos[i] < pos[i+1]) {
            count++;
        } else {
            maxCount = max(maxCount, count);
            count = 1;
        }
    }
    return max(maxCount, count);
}

int main() {
    int N;
    cin >> N;
    vector<int> temp;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        temp.push_back(n);
    }
    cout << temp.size() - lineUp(temp) << endl;
    return 0;
}