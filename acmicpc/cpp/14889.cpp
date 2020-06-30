#include <iostream>
#include <vector>
using namespace std;

int **StartLinkS;
int StartLinkAnswer;
vector<int> StartLinkV;

void calculateTeamSynergy(int* set, int set_size) {
    int synerge = 0;
    for (int i = 0; i < set_size; i++) {
        for (int j = i+1; j < set_size; j++) {
            synerge += StartLinkS[set[i]][set[j]] + StartLinkS[set[j]][set[i]];
        }
    }
    StartLinkV.push_back(synerge);
}

void StartLinkComb(int* set, int set_size, int m, int n, int index) {
    if (set_size == n) {
        calculateTeamSynergy(set, set_size);
        return;
    }
    if (m == index)
        return;
    
    set[set_size] = index;
    StartLinkComb(set, set_size+1, m, n, index+1);
    StartLinkComb(set, set_size, m, n, index+1);
}

int startLink() {
    int N;
    cin >> N;

    StartLinkS = new int*[N];
    
    for (int i = 0; i < N; i++) {
        StartLinkS[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> StartLinkS[i][j];
        }
    }
    
    int* set = new int[N]();
    StartLinkComb(set, 0, N, N/2, 0);
    
    int size = (int)StartLinkV.size();
    
    StartLinkAnswer = abs(StartLinkV[0]-StartLinkV[size-1]);
    for (int i = 1; i < size/2; i++) {
        int temp = abs(StartLinkV[i]-StartLinkV[size-i-1]);
        StartLinkAnswer = min(StartLinkAnswer, temp);
    }
    
    return StartLinkAnswer;
}

int main() {
    cout << startLink() << endl;
    return 0;
}