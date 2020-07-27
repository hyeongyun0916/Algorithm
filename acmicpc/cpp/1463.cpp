#include <bits/stdc++.h>
using namespace std;

vector<int> answers;

void makeOne(int num, int level) {
	if (answers[num] <= level) {
		return;
	}
	answers[num] = level;
	if (num <= 1) {
		return;
	}

	if (num%3 == 0) makeOne(num/3, level+1);
	if (num%2 == 0) makeOne(num/2, level+1);
	makeOne(num-1, level+1);	
}

int main() {
    //freopen("input.txt", "r", stdin);
	int num;
	cin >> num;
	answers.resize(num+1, 987654321);

	makeOne(num, 0);
	cout << answers[1] << endl;
	return 0;
}