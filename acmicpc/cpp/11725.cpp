#include <bits/stdc++.h>

using namespace std;

const int maxValue = 100001;
map <int, set<int>> nodes;
vector<int> roots(maxValue, 0);

void findRoot(int root) {
    for (int child : nodes[root]) {
        // nodes[child].erase(root);
        if (roots[child] != 0) continue;
        roots[child] = root;
        findRoot(child);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    roots[1] = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].insert(b);
        nodes[b].insert(a);
    }

    findRoot(1);

    for (int i = 2; i < n+1; i++) {
        cout << roots[i] << '\n';
    }

    return 0;
}