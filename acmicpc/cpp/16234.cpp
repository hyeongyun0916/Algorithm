#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

// 16234


struct MPoint {
    int x;
    int y;
    MPoint(int _x, int _y)
     : x(_x), y(_y) {}
};

int N;
int L, R;
vector<vector<int> > A;
vector<vector<int> > island;
vector<vector<int> > bundle;
int answer = -1;

void printVector(vector<vector<int> >& v) {
    for(int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void checkIsSameland(MPoint p) {
	island[p.x][p.y] = bundle.size() -1;
	// cout << "point: " << p.x << ' ' << p.y << ' ' << island[p.x][p.y] << endl;
	if (p.x > 0) {
		int diff = abs(A[p.x -1][p.y] - A[p.x][p.y]);
		if (island[p.x -1][p.y] == -1 && diff >= L && diff <= R) {
			bundle.back().push_back(A[p.x -1][p.y]);
			checkIsSameland(MPoint(p.x -1, p.y));
		}
	}
	if (p.y > 0) {
		int diff = abs(A[p.x][p.y-1] - A[p.x][p.y]);
		if (island[p.x][p.y -1] == -1 && diff >= L && diff <= R) {
			bundle.back().push_back(A[p.x][p.y -1]);
			checkIsSameland(MPoint(p.x, p.y -1));
		}
	}
	if (p.x < N -1) {
		int diff = abs(A[p.x +1][p.y] - A[p.x][p.y]);
		if (island[p.x +1][p.y] == -1 && diff >= L && diff <= R) {
			bundle.back().push_back(A[p.x +1][p.y]);
			checkIsSameland(MPoint(p.x +1, p.y));
		}
	}
	if (p.y < N -1) {
		int diff = abs(A[p.x][p.y +1] - A[p.x][p.y]);
		if (island[p.x][p.y +1] == -1 && diff >= L && diff <= R) {
			bundle.back().push_back(A[p.x][p.y +1]);
			checkIsSameland(MPoint(p.x, p.y +1));
		}
	}
}

void start() {
	answer++;
    fill(island.begin(), island.end(), vector<int> (N, -1));
	bundle.clear();
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (island[i][j] == -1) {
				vector<int> tempVec;
				tempVec.push_back(A[i][j]);
				bundle.push_back(tempVec);
				checkIsSameland(MPoint(i, j));
			}
		}
		
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// cout << island[i][j] << ' ' << accumulate(bundle[island[i][j]].begin(), bundle[island[i][j]].end(), 0) << endl;
			// printVector(bundle);
			A[i][j] = accumulate(bundle[island[i][j]].begin(), bundle[island[i][j]].end(), 0) / bundle[island[i][j]].size();
		}	
	}
	
	// cout << "bundle.size: " << bundle.size() << endl;
	if (bundle.size() != N*N) {
		start();
	}
}


int main() {
	cin >> N;
	cin >> L >> R;

	for (int i = 0; i < N; i++) {
		vector<int> tempVec;
		island.push_back(tempVec);
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			tempVec.push_back(temp);
		}
		A.push_back(tempVec);
	}
	
	start();

	cout << answer << endl;

	return 0;
}