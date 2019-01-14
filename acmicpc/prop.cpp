#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <string.h>

using namespace std;

// 1939, memory overflow...
vector< vector<int> > bridge;


int max_weight;
int min_weight;
int destination;
int N;

void find_max_weight(int pos, set<int> visit, int weight) {
    visit.insert(pos);
    if (pos == destination) {
        max_weight = max(max_weight, weight);
    }
    for (int i = 1; i < N; i++) {
        if (bridge[pos][i] && bridge[pos][i] > min_weight && visit.find(i) == visit.end()) {
            find_max_weight(i, visit, min(weight, bridge[pos][i]));
        }
    }
}

int main() {
    cin >> N;
    N++;
    
	bridge = vector< vector<int> >(N, vector<int>(N, 0));
    max_weight = 0;
    min_weight = __INT_MAX__;
    
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bridge[a][b] = c;
        bridge[b][a] = c;
        min_weight = min(min_weight, c);
    }

    int start;
    cin >> start >> destination;

    set<int> visit;
    find_max_weight(start, visit, __INT_MAX__);
    cout << max(max_weight, min_weight) << endl;

    return 0;
}