#include <bits/stdc++.h>
using namespace std;

void checkRemove(vector<string> &grid);

int countK = 0;
int n, K;
vector<vector<bool>> isChecked;


void printGrid(vector<string> grid) {
	for (int i = 0; i < n; i++) {
		cout << grid[i] << endl;
	}
	cout << endl;
}

void checkK(vector<string> &grid, char value, int x, int y) {
	if (grid[x][y] == value) {
		countK++;
		grid[x][y] += 10;
		
		if (x-1>=0)
			checkK(grid, value, x-1, y);
		if (x+1<n)
			checkK(grid, value, x+1, y);		
		if (y-1>=0) 
			checkK(grid, value, x, y-1);
		if (y+1<10)
			checkK(grid, value, x, y+1);
	}
}

void changeGrid(vector<string> &grid, char originValue, char newValue, int x, int y) {
	if (grid[x][y] == originValue) {
		grid[x][y] = newValue;
		
		if (x-1>=0)
			changeGrid(grid, originValue, newValue, x-1, y);
		if (x+1<n)
			changeGrid(grid, originValue, newValue, x+1, y);
		if (y-1>=0)
			changeGrid(grid, originValue, newValue, x, y-1);
		if (y+1<10)
			changeGrid(grid, originValue, newValue, x, y+1);
	}
}


void moveToDown(vector<string> &grid) {
	for (int j = 0; j < 10; j++) {
		for (int i = n-1; i > 0; i--) {
			
			bool isDowned = true;
			
			while (isDowned && grid[i][j] == '0') {
				isDowned = false;
			
				for (int k = i; k > 0; k--) {
					if (grid[k-1][j] != '0')
						isDowned = true;
					grid[k][j] = grid[k-1][j];
				}
				grid[0][j] = '0';
				// printGrid(grid);
			}
			
			if (grid[i][j] > '9') {
				grid[i][j] -= 10;
			}
		}
		
	}
	// printGrid(grid);
	checkRemove(grid);
}

void changeToNumber(vector<string> &grid) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (grid[i][j] > '9') {
				grid[i][j] -= 10;
			}
		}
	}
	
	// printGrid(grid);
}

void checkRemove(vector<string> &grid) {
	bool isChanged = false;
	
	isChecked.clear();
	for (int i = 0; i < n; i++) {
		vector<bool> tempBool(10, false);
		isChecked.push_back(tempBool);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (grid[i][j] >= '1' && grid[i][j] <= '9') {
				countK = 0;
				checkK(grid, grid[i][j], i, j);
				// printGrid(grid);
				if (countK >= K) {
					changeGrid(grid, grid[i][j], '0', i, j);
					isChanged = true;
				}
			}
		}
	}

	if (isChanged)
		moveToDown(grid);
	else
		changeToNumber(grid);
}

int main(){
	cin >> n >> K;
	vector<string> grid;
	for (int i = 0; i < n; i++) {
		string tempStr;
		cin >> tempStr;
	 	grid.push_back(tempStr);
	}
	
	
	/*
	for (int i = 0; i < 10; i++) {
		cout << char(48+i) << ' ' << char(48+i+10) << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << char(48+i) << ' ' << char(48+i-10) << endl;
	}
	*/
	
	
	// moveToDown(grid);
	// printGrid(grid);		
	checkRemove(grid);
	printGrid(grid);
	
	
	return 0;
}