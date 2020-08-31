#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
	int n, m;
	string s;
	vector<int> v;

	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < m-2; i++) {
		int cnt = 0;
		if (s[i] == 'I') {
			while (i < m-2 && s[i+1] == 'O' && s[i+2] == 'I') {
				i += 2;
				cnt++;
			}
		}
		v.push_back(cnt);
	}

	int answer = 0;
	for (int i = 0; i < v.size(); i++) answer += max(0, v[i]-n+1);
	cout << answer << endl;

	return 0;
}