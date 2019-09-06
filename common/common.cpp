#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 987654321
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <ctime>
#include <regex>
#include <random>
#include <iterator>
#include <functional>
#pragma warning(disable : 4996)

using namespace std;

struct TreeNode {
    string label;
	TreeNode* parent;
	vector<TreeNode*> children;
};

void printLabels(TreeNode* root) {
	cout << root->label << endl;
	for (int i = 0; i < root->children.size(); i++) {
		printLabels(root->children[i]);
	}
}

// - 가장긴잎 잎
int longest;
int height(TreeNode* root) {
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	if (heights.empty())
		return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	return heights.back() + 1;
}

int solve(TreeNode* root) {
	longest = 0;
	int h = height(root);
	return max(longest, h);
}


//bfs
vector<vector<int>> adj;
vector<int> bfs(int start) {
	vector<bool> discovered(adj.size(), false);
	queue<int> q;
	vector<int> order;
	discovered[start] = true
		q.push(start);
	while (!q.empty()){
		int here = q.front();
		q.pop();
		order.push_back(here);
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}

const int V; //정점의갯수
vector<pair<int, int>> adj1[V];
vector<int> dijkstra2(int src) {
	vector<int> dist(V, 987654321);
	vector<bool> visited(V, false);
	dist[src] = 0;
	visited[src] = false;
	while (true) {
		int closest = 987654321, here;
		for (int i = 0; i < V; ++i) {
			if (dist[i] < closest && !visited[i]) {
				here = i;
				closest = dist[i];
			}
		}
		if (closest == 987654321)
			break;
		visited[here] = true;
		for (int i = 0; i < adj1[here].size(); ++i) {
			int there =
				adj1[here][i].first;
			if (visited[there])
				continue;
			int nextDist =
				dist[here] + adj1[here][i].second;
			dist[there] =
				min(dist[there], nextDist);
		}
	}
}
int adj2[V][V];
int via[V][V];
void floyd() {
	for (int i = 0; i < V; ++i)
		adj2[i][i] = 0;
	memset(via, -1, sizeof(via));
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V;
				++j)
				if (adj2[i][j] >
					adj[i][k] + adj[k][j]) {
					via[i][j] = k;
					adj[i][j] =
						adj[i][k] + adj[k][j];
				}
}
//경로
void reconstruct(int u, int v,
	vector<int>& path) {
	if (via[u][v] == -1) {
		path.push_back(u);
		if (u != v)
			path.push_back(v);
	}
	else {
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back();
		reconstruct(w, v, path);
	}
}
int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p%q);
}
// a^p = 1 mod p
#pragma warning(disable : 4996)
vector<int> getPi(string p){
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++){
		while (j > 0 && p[i] !=
			p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
vector<int> kmp(string s, string
	p){
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m =
		(int)p.size(), j = 0;
	for (int i = 0; i < n; i++){
		while (j>0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]){
			if (j == m - 1){

				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else{
				j++;
			}
		}
	}
	return ans;
}
void regexTest() {
	// regex
	pattern("(\\w+[\\w\\.]*)@(\\w+[\\w\\.] * \\.[A - Za - z] + )");
	// regex
	pattern("@gmail.com$");
	regex pattern("\\w+p+\\w");
	string strArr[3][2] = { { "aa", "Soo@gmail.comKpkaRak@gmaiel.com" },
	{ "bb", "Soo@gmail.comKkaRak@gmail.com" },
	{ "cc", "Soo@gmail.com$" } };
	smatch m;
	for (int i = 0; i < 3; i++) {
		if (regex_search(strArr[i][1], m, pattern)) {
			cout << " : " << strArr[i][0] << endl;
			// for (size_t i = 0; i < m.size(); i++)
			// cout << i << " : " << m[i] << endl; 번째
		}
		else
			cout << "Not Match" << endl;
	}
}
void CComb(int* set, int set_size,
	int m, int n, int index) {
	if (set_size == n) {
		Print_set(set, set_size);
		return
	}
	if (m == index)
		return
		set[set_size] = index;
	CComb(set, set_size + 1, m, n,
		index + 1);
	CComb(set, set_size, m, n, index
		+ 1);
}
void HRComb(int* set, int
	set_size, int m, int n, int index) {
	if (set_size == n) {
		Print_set(set, set_size);
		return
	}
	else if (index == m) return
		set[set_size] = index;
	HRComb(set, set_size + 1, m, n,
		index);
	HRComb(set, set_size, m, n, index
		+ 1);
}
void PPerm(int* set, int set_size,
	int m, int n) {
	if (set_size == n) {
		Print_set(set, set_size);
		return
	}
	for (int i = set_size; i < m; i++) {
		swap(set[i], set[set_size]);
		PPerm(set, set_size + 1, m, n);
		swap(set[i], set[set_size]);
	}
}
void PiRPerm(int* set, int
	set_size, int m, int n) {
	if (set_size == n) {
		Print_set(set, set_size);
		return
	}
	for (int i = 0; i < m; i++) {
		set[set_size] = i;
		PiRPerm(set, set_size + 1, m, n);
	}
}
void main() {
	int m = 6, n = 3; //mCn mHn
	mPn mPin
		int* set = new int[n]();
	int* arr = new int[n]();
	for (int i = 0; i < m; i++) {
		arr[i] = i;
	}
	cout << "mCn" << endl;
	CComb(set, 0, m, n, 0);
	cout << endl;
	cout << "mHn" << endl;
	HRComb(set, 0, m, n, 0);
	cout << endl;
	cout << "mPn" << endl;
	PPerm(arr, 0, m, n);
	cout << endl;
	cout << "m n" << endl; ㅠ
		PiRPerm(arr, 0, m, n);
	cout << endl;
}
struct a{
	int start;
	int end;
	int value;
};
struct cmp{
	bool operator()(a t, a u){
		return t.value < u.value;
	}
};
void tempFunction() {
	priority_queue < a, vector<a>, cmp > pq;
	// //셔플
	// vector<int> temp;
	// random_device rnd_device;
	// mt19937
	mersenne_engine(rnd_device());
	// shuffle(begin(temp),end(temp), mersenne_engine);
	srand((unsigned int)time(NULL));
	rand() % 1000;
	map<int, int> maxMap;
	maxMap.insert(pair<int, int>(picture[i][j], maxMap[picture[i][j]]++));

	unordered_set<string>::iterator i = wordList.find(tempStr);
	if (i != wordList.end())
		for (string a : wordList)
			cout << a << endl;
	wordList.erase(tempStr);
	wordList.insert(endWord);
}

//빌라봉
vector<vector<pair<int, int>>> a;
long long dist1[100003],
dist2[100003];
int back[100003], check[100003],
vertex[100003], v, u;
long long r, g;
int node[100003];
void dfs(int here, long long dis,
	int numTree) {
	dist1[here] = dis;
	if (dist1[here] > r) {
		r = dist1[here];
		u = here;
	}
	for (auto next : a[here]) {
		if (dist1[next.first] != INF)
			continue;
		if (vertex[next.first] != numTree)
			continue;
		dfs(next.first, dis + next.second, numTree);
	}
}
void diameter(int here, long long
	dis, int numTree) {
	dist2[here] = dis;
	if (dist2[here] > r) {
		r = dist2[here];
		u = here;
	}
	for (auto next : a[here]) {
		if (dist2[next.first] != INF)
			continue;
		if (vertex[next.first] != numTree)
			continue;
		diameter(next.first, dis + next.second, numTree);
		back[next.first] = here;
	}
}
int main() {
	int m, n, l, numTree = 1;
	optimizar_io
	cin >> n >> m >> l;
	a.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		a[from].push_back(make_pair(to, cost));
		a[to].push_back(make_pair(from, cost));
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			queue<int> q;
			check[i] = true;
			vertex[i] = numTree;
			node[numTree] = i;
			q.push(i);
			while (!q.empty()) {
				int here = q.front();
				q.pop();
				for (int i = 0; i < a[here].size(); i++)
				{
					auto next = a[here][i];
					if (!check[next.first]) {
						check[next.first] = true
							vertex[next.first] = numTree;
						q.push(next.first);
					}
				}
			}
			numTree++;
		}
	}
	for (int i = 0; i < 100003; i++){
		dist1[i] = dist2[i] = INF;
		back[i] = -1;
	}
	vector<long long> ans;
	long long result = 0;
	for (int i = 1; i < numTree; i++) {
		u = node[i], r = 0;
		dfs(node[i], 0, i);
		v = u, r = 0;
		diameter(v, 0, i);
		result = max(result, r);
		int it = u;
		g = INF;
		while (it != -1) {
			long long rad = max(dist2[it], r - dist2[it]);
			g = min(g, rad);
			it = back[it];
		}
		ans.push_back(g);
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	if (ans.size() > 1) {
		result = max(result, ans[0] + ans[1] + l);
		if (ans.size() > 2)
			result = max(result, ans[1] + ans[2] + 2 * l);
	}
	cout << result;
}

void main() {
	string s = "34";
	int i = atoi(s.c_str());
	cout << s << endl << i << endl;
	i = 57;
	s = to_string(i);
	cout << s << endl << i << endl;
	s = "31";
	i = stoi(s);
	cout << s << endl << i << endl;
	const char* ch = s.c_str();
	cout << ch << endl;
	char* chArr = "aaa";
	s = chArr;
	cout << chArr << endl << s <<
		endl;
	s = "bbb";
	string temp = "cfk"
		cout << endl << temp.size() << endl << temp.length() << endl << endl;
	char * tab2 = new char[temp.length() + 1];
	tab2 = "afaaffff";
	strcpy(tab2, temp.c_str());
	//strcpy_s(tab2, temp.size() + 1,
	temp.c_str();
	cout << tab2 << endl;
}

// 프로젝트 구성속성 링커 시스템 하위시스템 콘솔