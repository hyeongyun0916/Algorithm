#include <bits/stdc++.h>
using namespace std;

/*
빠르고 간단하게 dfs로 풀려다가 
시간초과로 결국 bfs
*/

/*
vector<int> answers;
int n, k;

void findK(int current, int level) {
	if (current < 0 || current > 100000) return;
	if (answers[current] <= level || answers[k] <= level) return;

	answers[current] = level;
	if (current == k) return;

	level += 1;
	findK(2*current, level);
	findK(current+1, level);
	findK(current-1, level);
}

int main() {
    freopen("input.txt", "r", stdin);
	cin >> n >> k;

	answers.resize(100001, 987654321);

	findK(n, 0);

	cout << answers[k] << endl;

	return 0;
}
*/

struct Node {
    int pos;
	int count;
    Node(int _pos, int _count)
     : pos(_pos), count(_count) {}
};

vector<int> answers;
int n, k;

int main() {
    // freopen("input.txt", "r", stdin);
	cin >> n >> k;

	answers.resize(100001, 987654321);
	queue<Node> q;
	q.push(Node(n, 0));

	while (!q.empty()) {
		Node temp = q.front();
		q.pop();

		if (temp.pos == k) {
			cout << temp.count << endl;
			return 0;
		}

		if (temp.pos *2 <= 100000) {
			if (temp.count+1 < answers[temp.pos*2]) {
				answers[temp.pos*2] = temp.count+1;
				q.push(Node(temp.pos*2, temp.count+1));
			}				
		}
		if (temp.pos < 100000) {
			if (temp.count+1 < answers[temp.pos+1]) {
				answers[temp.pos+1] = temp.count+1;
				q.push(Node(temp.pos+1, temp.count+1));
			}
		}
		if (temp.pos > 0) {
			if (temp.count+1 < answers[temp.pos-1]) {
				answers[temp.pos-1] = temp.count+1;
				q.push(Node(temp.pos-1, temp.count+1));
			}
		}
	}

	return 0;
}