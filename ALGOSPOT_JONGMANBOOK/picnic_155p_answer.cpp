#include <bits/stdc++.h>
using namespace std;

int n, m;
bool areFriends[10][10];    //친구의 최대 수는 10
bool taken[10];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			areFriends[i][j] = false;
		taken[i] = false;
	}
}

int countPairing(bool taken[10]) {
    // 짝을 안지은 학생 중 첫번쨰 학생
    int firstFree = -1;

    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;
    int ret = 0;

    for (int pairWith = firstFree +1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairing(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

// https://www.algospot.com/judge/problem/read/PICNIC
int main() {
    freopen("ALGOSPOT_JONGMANBOOK/input.txt", "r", stdin);
    
    int cases;
	int pair_i,pair_j;
	

	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n >> m;
		
		init();

		for (int j = 0; j < m; j++) {
			cin >> pair_i >> pair_j;
			areFriends[pair_i][pair_j] = true;
			areFriends[pair_j][pair_i] = true;
		}

		cout << countPairing(taken) << '\n';

	}
    
    return 0;
}