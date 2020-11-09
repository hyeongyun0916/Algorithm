#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> tree;
int answer;

void findLeaf(int current) {
    for (int child: tree[current]) {
        if (tree.find(child) == tree.end()) {
            answer += 1;
            continue;
        }
        findLeaf(child);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) cin >> temp[i];
    int eraseNode;
    cin >> eraseNode;
    
    int parent;
    for (int i = 0; i < n; i++) {
        parent = temp[i];
        if (parent == eraseNode || i == eraseNode) continue;
        tree[parent].push_back(i);
    }

    answer = 0;
    if (tree[-1].size())
        if (tree.find(tree[-1][0]) == tree.end()) answer = 1;
        else findLeaf(tree[-1][0]);
    cout << answer << endl;

    return 0;
}