#include <bits/stdc++.h>

using namespace std;

int globalN;
vector<vector<bool>> frames;

void printVector(vector<vector<bool>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isPillarPossible(int a, int b) {
    return 
    (a == 1)
    || (a-2 >= 0 && frames[a-2][b])
    || (a-1 >= 0 && b-1 >= 0 && frames[a-1][b-1])
    || (a-1 >= 0 && b+1 < globalN && frames[a-1][b+1]);
}

bool isPaperPossible(int a, int b) {
    return
    (b-2 >= 0 && b+2 < globalN && frames[a][b-2] && frames[a][b+2])
    || (a-1 >= 0 && b-1 >= 0 && frames[a-1][b-1])
    || (a-1 >= 0 && b+1 < globalN && frames[a-1][b+1]);
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<tuple<int, int, int>> s;
    globalN = 2*n+1;
    frames.assign(globalN, vector<bool>(globalN, false));
    
    for (int i = 0; i < build_frame.size(); i++) {
        int a, b;
        if (build_frame[i][2] == 0) {
            a = build_frame[i][1]*2+1;
            b = build_frame[i][0]*2;
            if (build_frame[i][3]) {
                if (isPillarPossible(a, b)) {
                    s.insert(make_tuple(build_frame[i][0], build_frame[i][1], build_frame[i][2]));
                    frames[a][b] = true;
                }
            } else {
                frames[a][b] = false;
                if ((a+1 >= globalN || b-1 < 0 || !frames[a+1][b-1] || isPaperPossible(a+1, b-1))
                && (a+1 >= globalN || b+1 >= globalN || !frames[a+1][b+1] || isPaperPossible(a+1, b+1))
                && (a+2 >= globalN || !frames[a+2][b] || isPillarPossible(a+2, b))) {
                    s.erase(make_tuple(build_frame[i][0], build_frame[i][1], build_frame[i][2]));
                } else {
                    frames[a][b] = true;
                }
            }
        } else {
            a = build_frame[i][1]*2;
            b = build_frame[i][0]*2+1;
            if (build_frame[i][3]) {
                if (isPaperPossible(a, b)) {
                    s.insert(make_tuple(build_frame[i][0], build_frame[i][1], build_frame[i][2]));
                    frames[a][b] = true;
                } 
            } else {
                frames[a][b] = false;
                if ((b-2 < 0 || !frames[a][b-2] || isPaperPossible(a, b-2))
                && (b+2 >= globalN || !frames[a][b+2] || isPaperPossible(a, b+2))
                && (a+1 >= globalN || b-1 < 0 || !frames[a+1][b-1] || isPillarPossible(a+1, b-1))
                && (a+1 >= globalN || b+1 >= globalN || !frames[a+1][b+1] || isPillarPossible(a+1, b+1))) {
                    s.erase(make_tuple(build_frame[i][0], build_frame[i][1], build_frame[i][2]));
                } else {
                    frames[a][b] = true;
                }
            }
        }
    }
    
    // sort(answer.begin(), answer.end());

    for (auto f : s) {
        vector<int> v = {get<0>(f), get<1>(f), get<2>(f)};
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
        answer.push_back(v);
    }

    return answer;
}

int main() {
    vector<vector<int>> build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
    solution(5, build_frame);
    return 0;
}