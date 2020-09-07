#include <bits/stdc++.h>
using namespace std;

struct Node {
    int num;
    string cmd;
    Node(int _num, string _cmd)
     : num(_num), cmd(_cmd) {}
};

int main() {
    // freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		queue<Node> q;
		vector<bool> visited(10001, false);
		int a, b;
		cin >> a >> b;
        visited[a] = true;
		q.push(Node(a, ""));
		while (!q.empty()) {
			Node current = q.front();
			q.pop();
            
            if (current.num == b) {
                cout << current.cmd << endl;
                break;
            }

			int temp = (current.num*2)%10000;
			if (temp == b) {
				cout << current.cmd+"D" << endl;
				break;
			} else if (!visited[temp]) {
				visited[temp] = true;
				q.push(Node(temp, current.cmd+"D"));
			}
			

			temp = current.num -1;
			if (temp == -1) temp = 9999;
			if (temp == b) {
				cout << current.cmd+"S" << endl;
				break;
			} else if (!visited[temp]) {
				visited[temp] = true;
				q.push(Node(temp, current.cmd+"S"));
			}

			temp = (current.num%1000)*10+(current.num/1000);
			if (temp == b) {
				cout << current.cmd+"L" << endl;
				break;
			} else if (!visited[temp]) {
				visited[temp] = true;
				q.push(Node(temp, current.cmd+"L"));
			}

			temp = (current.num/10)+(current.num%10)*1000;
			if (temp == b) {
				cout << current.cmd+"R" << endl;
				break;
			} else if (!visited[temp]) {
				visited[temp] = true;
				q.push(Node(temp, current.cmd+"R"));
			}
		}
	}
}