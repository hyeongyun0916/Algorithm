#include <bits/stdc++.h>
using namespace std;


// 북 동 남 서

int n, m;
int answer = 0;

void printMap(vector<vector<int>> &robotMap) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << robotMap[i][j] << ' ';
		}
		cout << endl;
	}
	//cout << endl;
}

/*
void backTwoRobot(int &r, int &c, int d) {
	
}

void goOneRobot(int &r, int &c, int d) {
	switch(d) {
		
	}
}
*/

bool backTwoRobot(vector<vector<int>> &robotMap, int &r, int &c, int d) {
	switch (d) {
		case 0:
			if (r < n && robotMap[r+1][c] != 1) {
				r += 1;
				return true;
			} else {
				return false;
			}
			break;
		case 1:
			if (c > 0 && robotMap[r][c-1] != 1) {
				c -= 1;
				return true;
			} else {
				return false;
			}
			break;
		case 2:
			if (r > 0 && robotMap[r-1][c] != 1) {
				r -= 1;
				return true;
			} else {
				return false;
			}
			break;
		case 3:
			if (c < m && robotMap[r][c+1] != 1) {
				c += 1;
				return true;
			} else {
				return false;
			}
			break;
	}
}

bool goOneRobot(vector<vector<int>> &robotMap, int &r, int &c, int d) {
	switch (d) {
		case 0:
			if (r > 0 && robotMap[r-1][c] == 0) {
				r -= 1;
				return true;
			} else {
				return false;
			}
			break;
		case 1:
			if (c < m && robotMap[r][c+1] == 0) {
				c += 1;
				return true;
			} else {
				return false;
			}
			break;
		case 2:
			if (r < n && robotMap[r+1][c] == 0) {
				r += 1;
				return true;
			} else {
				return false;
			}
			break;
		case 3:
			if (c > 0 && robotMap[r][c-1] == 0) {
				c -= 1;
				return true;
			} else {
				return false;
			}
			break;
	}
}

int rotateRobot (int d) {
	d -= 1;
	if (d == -1) d = 3;
	return d;
}

void findDirty(vector<vector<int>> &robotMap, int r, int c, int d) {
	int epoch = 0;

	bool flag = true;
	while (flag) {
		if (robotMap[r][c] == 0) {
			answer++;			
		}
		
		flag = false;
		
		// cout << r << ' ' << c << endl << endl;
		robotMap[r][c] = -1;

		for (int i = 0; i < 4; i++) {
			d = rotateRobot(d);
			if (goOneRobot(robotMap, r, c, d)) {
				flag = true;
				break;
			}
		}
		
		if (!flag && backTwoRobot(robotMap, r, c, d)) {
			flag = true;
		}
		
		/*
		epoch++;
		printMap(robotMap);
		if (epoch > 100) {
			flag = false;
		}
		*/
	}
}


int main(){
	cin >> n >> m;
	
	int r, c, d;
	cin >> r >> c >> d;
	
	
	vector<vector<int>> robotMap;
	
	for (int i = 0; i < n; i++) {
		vector<int> tempVec;
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			tempVec.push_back(temp);
		}
		robotMap.push_back(tempVec);
	}
	
	findDirty(robotMap, r, c, d);
	
	cout << answer << endl;
		
	return 0;
}