#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int answer = 0;

//nCk
int main() {
	int N, M;
	cin >> N >> M;
	int answer = 0;
	vector<int> intVec; //{5,6,7,8,9};
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		intVec.push_back(temp);
	}
	vector<int> ind;
	int k = 3;
	for (int i = 0; i < intVec.size() - k; i++) {
		ind.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}
	do {
		int sum = 0;
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1){
				// cout << intVec[i] << ' ';
				sum += intVec[i];
			}
		}
		if (sum <= M) {
			answer = answer > sum ? answer : sum;
		}
	} while(next_permutation(ind.begin(), ind.end()));
	cout << answer << endl;
	return 0;
}