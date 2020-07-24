#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> dfsAnswer, bfsAnswer;
vector<int> visited;
int n, m, v;

void dfsFunc(int current) {
	visited[current] = true;
	dfsAnswer.push_back(current);

	for (int i = 0; i < n; i++) {
		if (graph[current][i] && !visited[i]) {
			dfsFunc(i);
		}
	}
}

void bfsFunc(int current) {
	queue<int> bfsQ;
	bfsQ.push(current);
	visited[current] = true;
	bfsAnswer.push_back(current);

	while (!bfsQ.empty()) {
		current = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < n; i++) {
			if (graph[current][i] && !visited[i]) {
				bfsQ.push(i);
				visited[i] = true;
				bfsAnswer.push_back(i);
			}
		}
	}
	
}

void printVector(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

	cin >> n >> m >> v;

	n += 1;
	graph.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) graph[i].resize(n);

	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		graph[temp1][temp2] = 1;
		graph[temp2][temp1] = 1;
	}
	
	dfsFunc(v);
	visited.clear();
	visited.resize(n);
	bfsFunc(v);

	printVector(dfsAnswer);
	printVector(bfsAnswer);

    return 0;
}