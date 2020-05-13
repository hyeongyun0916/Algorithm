#include <bits/stdc++.h>
using namespace std;


void printMap(vector<vector <unsigned int>> robotMap) {
	int n = robotMap.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			switch (robotMap[i][j]) {
				case 0:
					cout << '.';
					break;
				case 1:
					cout << '-';
					break;
				case 2:
					cout << '|';
					break;
				case 3:
					cout << '+';
					break;
			}
		}
		cout << endl;
	}
}

int main(){
	int x=0, y=0;
	int n;
	cin >> n;
	string route;
	cin >> route;

	// left, right = 1
	// up, down = 2	
	vector<vector <unsigned int>> robotMap;
	for (int i = 0; i < n; i++) {
		vector<unsigned int> temp(n,0);
		robotMap.push_back(temp);
	}
	
	
	// xy가 범위 밖?
	switch(route[0]) {	
		case 'R':
			if (y+1<n) {	
				robotMap[x][y] |= 1;
				y+=1;
				robotMap[x][y] |= 1;	
			}
			break;
		
		case 'D':
			if (x+1<n) {	
				robotMap[x][y] |= 2;
				x+=1;
				robotMap[x][y] |= 2;	
			}
			break;
	}
	//printMap(robotMap);
	//cout << route[0] << ' ' << x << ' ' << y << endl << endl;
	
	for (int i = 1; i < route.size(); i++) {
		switch(route[i]) {	
			case 'R':
				if (y+1<n) {	
					robotMap[x][y] |= 1;
					y+=1;
					robotMap[x][y] |= 1;	
				}
				break;
				
				
			case 'L':
				if (y-1>=0) {	
					robotMap[x][y] |= 1;
					y-=1;
					robotMap[x][y] |= 1;	
				}
				break;
		
			case 'D':
				if (x+1<n) {	
					robotMap[x][y] |= 2;
					x+=1;
					robotMap[x][y] |= 2;	
				}
				break;
		
			case 'U':
				if (x-1>=0) {	
					robotMap[x][y] |= 2;
					x-=1;
					robotMap[x][y] |= 2;	
				}
				break;
		}
		//printMap(robotMap);
		//cout << route[i] << ' ' << x << ' ' << y << endl << endl;
	}
	
	printMap(robotMap);
	return 0;
}