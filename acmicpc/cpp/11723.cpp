#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m;
	string cmd;
	int x;
	vector<int> v(21);
	cin >> m;
	while (m--) {
		cin >> cmd;
		switch (cmd[1])
		{
		case 'd':
			cin >> x, v[x] = 1;
			break;
		case 'e':
			cin >> x, v[x] = 0;
			break;
		case 'h':
			cin >> x, cout << v[x] << '\n';
			break;
		case 'o':
			cin >> x, v[x] ^= 1;
			break;
		case 'l':
			for (int i = 1; i < 21; i++) v[i] = 1;
			break;
		
		default:
			for (int i = 1; i < 21; i++) v[i] = 0;
			break;
		}
	}

	return 0;
}