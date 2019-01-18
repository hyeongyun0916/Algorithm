#include <iostream>
#include <cmath>

using namespace std;

//acmicpc 2909
//왜 틀렸는지 모르겠다
//문제 조건이 불충분한것인가?

int myAnswer(double candy, int money) {
	if (!candy) {
		return 0;
	}
	int result = round(candy / money) * money;
	if (!result) result += money;
	return result;
}

int otherAnswer(double candy, int money) {
	int result = candy / money * money;
	if((int) candy % money >= money / 2) result += money;
	return result;
}

int main() {
	double candy, digit;
	cin >> candy >> digit;
	if (!candy) {
		cout << 0 << endl;
		return 0;
	}
	int money = pow(10,digit);
	int result = round(candy / money) * money;
	if (!result) result += money;
	cout << result << endl;
	return 0;
}