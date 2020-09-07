#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		map<int, int> m;
		int n;
		char cmd;
		int temp;

		cin >> n;
		while (n--) {
			cin >> cmd >> temp;
			if (cmd == 'I')	m[temp]++;
			else {
				if (m.empty()) continue;
				map<int, int>::iterator it;
				if (temp == 1) it = --m.end();
				else it = m.begin();

				if (--(it->second) == 0) m.erase(it);
			}
		}
		if (m.empty()) {
			cout << "EMPTY" << endl;
		} else {
			cout << (--m.end())->first << ' ' << m.begin()->first << endl;
		}
	}

	return 0;
}