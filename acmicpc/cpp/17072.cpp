#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s;
		for (int j = 0; j < m; j++) {
			int r, g, b;
			cin >> r >> g >> b;
			long value = 2126*r + 7152*g + 722*b;
			if (value < 510000)
				s += 35;
			else if (value < 1020000)
				s += 111;
			else if (value < 1530000)
				s += 43;
			else if (value < 2040000)
				s += 45;
			else
				s += 46;
		}
		cout << s << endl;
	}
	
	return 0;
}