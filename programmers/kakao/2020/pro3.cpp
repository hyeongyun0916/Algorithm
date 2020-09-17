#include <bits/stdc++.h>
using namespace std;

int rows, cols;

// vector<vector<int>> rotate(vector<vector<int>> &key) {
//     int n = key.size();
// 	vector<vector<int>> newKey(n, vector<int>(n, 987654321));
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             newKey[i][j] = key[rows-1-j][i];
//         }
//     }
//     return newKey;
// }

void rotate(vector<vector<int>> &mat) 
{ 
    int N = mat.size();
    for (int x = 0; x < N / 2; x++) { 
        for (int y = x; y < N - x - 1; y++) { 
            int temp = mat[x][y]; 
            mat[x][y] = mat[y][N - 1 - x]; 
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
            mat[N - 1 - y][x] = temp; 
        } 
    } 
} 

bool check(vector<vector<int>> key, vector<vector<int>> lock, int startI, int startJ) {

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            lock[i+startI][j+startJ] += key[i][j];
        }
    }

    int lSize = lock.size() - 2 * (key.size() - 1);
    for (int i = 0; i < lSize; i++) {
        for (int j = 0; j < lSize; j++) {
            if (lock[i+key.size()-1][j+key.size()-1] != 1) return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    vector<vector<int>> newLock((key.size()-1)*2+lock.size(), vector<int>((key.size()-1)*2+lock.size(), 0));

    bool isAlready = true;
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (!lock[i][j]) isAlready = false;
            newLock[i+key.size()-1][j+key.size()-1] = lock[i][j];
        }
    }

    if (isAlready) return true;

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < newLock.size() - key.size(); i++) {
            for (int j = 0; j < newLock.size() - key.size(); j++) {
                if (check(key, newLock, i, j)) return true;
            }
        }
        rotate(key);
    }

    return false;
}

int main() {
    // [[0, 0, 0], [1, 0, 0], [0, 1, 1]]	[[1, 1, 1], [1, 1, 0], [1, 0, 1]]	true
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout << solution(key, lock) << endl;
    return 0;
}