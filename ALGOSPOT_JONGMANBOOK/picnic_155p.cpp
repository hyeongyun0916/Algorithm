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
            people[friends[i].first] = people[friends[i].second] = true;
            makeFriends(people, i); // 처음에는 복사배열을 만들어서 넘겼다가, 종만북을 보고 원복하는 것으로 고침
            people[friends[i].first] = people[friends[i].second] = false;
        }
    }
}

// https://www.algospot.com/judge/problem/read/PICNIC

/* 
    내 방법
    1. 친구를 한쪽만 만듦
        => 입력이 오름차순이 아닐 경우, 친구를 양 쪽으로 만들어 주는 것이 좋을 듯.
    2. 친구를 백터와 pair로 만듦
        => 친구를 2차원 배열로 만들어서 i j가 친구일 경우 friends[i][j] = true로 만드는 것이 좋을 듯.
    3. makeFriends에서 복사 배열로 넘김
        => 복사 배열이 아닌 배열 하나로 넣었다가 원래대로 돌리는 것이 좋을 듯
*/

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