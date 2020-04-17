#include <bits/stdc++.h>
using namespace std;

int total;
vector<pair<int, int>> friends;

void makeFriends(vector<bool> people, int beforePos) {

    bool didMakeFriend = true;
    for (int i = 0; i < people.size(); i++) {
        if (!people[i]) didMakeFriend = false;
    }
    if (didMakeFriend) {
        total += 1;
        return;
    }
    
    for (int i = beforePos+1; i < friends.size(); i++) {
        if (!people[friends[i].first] && !people[friends[i].second]) {
            vector<bool> temp(people);
            temp[friends[i].first] = temp[friends[i].second] = true;
            makeFriends(temp, i);
        }
    }
}

// https://www.algospot.com/judge/problem/read/PICNIC
int main() {
    freopen("ALGOSPOT_JONGMANBOOK/input.txt", "r", stdin);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        total = 0;
        friends.clear();

        int n, m;
        cin >> n >> m;

        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            friends.push_back(make_pair(a, b));
        }

        vector<bool> people(n);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                people[k] = false;
            }
            people[friends[j].first] = true;
            people[friends[j].second] = true;
            makeFriends(people, j);
        }

        cout << total << endl;
    }
    return 0;
}