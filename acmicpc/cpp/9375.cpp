#include <bits/stdc++.h>
using namespace std;


/*

arr = [a, b, c, d] 가 있을 때
comb(arr, 1) // a + b + c + d
+ comb(arr, 2) // ab + ac + ad + bc + bd + cd
+ comb(arr, 3) // abc + abd + acd + bcd
+ comb(arr, 4) // abcd
를 구하는 문제.

처음에는 python의 itertools를 이용 => 시간초과
두번째는 dfs로 combination값을 바로 곱함 => 시간초과
세번째는 https://www.geeksforgeeks.org/sum-products-combination-taken-1-n-time/ 를 참고하여
dp 및 분배법칙을 활용하여 문제 풀이 => 맞음
	postfix는 합을 땡겨오고 modify는 곱을 땡겨옴
	postfix는 [ab + ac, bc] 로 나뉘어져있던 것을 [ab + ac + bc]로 만드는 작업
	modify는 [a+b+c, b+c, c]로 되어있는 것을 [a(b+c), b(c)]로 만드는 작업
네번째는 다른 분의 풀이 참고. => 구하고자 하는 식은 (a+1)(b+1)(c+1)(d+1)-1 을 전개한 값과 동일하다...!!!!!

수학적으로 접근했다면 쉬운 문제를,
돌아돌아 풀음...

*/


int answer = 0;

// find the postfix sum array
void postfix(vector<int> &a, int n)
{
	for (int i = n - 1; i > 0; i--)
		a[i - 1] = a[i - 1] + a[i];
}

// modify the array such that we don't have to
// compute the products which are obtained before
void modify(vector<int> &a, vector<int> &sample, int n)
{
	for (int i = 1; i < n; i++)
		a[i - 1] = sample[i - 1] * a[i];
}

// finding sum of all combination taken 1 to N at a time
void allCombination(vector<int> &a, int n)
{

	int sum = 0;
	vector<int> sample(a);

	// sum taken 1 at time is simply sum of 1 - N
	for (int i = 0; i < n; i++)
		sum += a[i];
	// cout << "f(1) --> " << sum << "\n";
	answer += sum;

	// for sum of products for all combination
	for (int i = 1; i < n; i++)
	{

		// finding postfix array
		postfix(a, n - i + 1);

		// sum of products taken i+1 at a time
		sum = 0;
		for (int j = 1; j <= n - i; j++)
		{
			sum += (sample[j - 1] * a[j]);
		}
		// cout << "f(" << i + 1 << ") --> " << sum << "\n";
		answer += sum;

		// modify the array for overlapping problem
		modify(a, sample, n);
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		map<string, int> clothes;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			clothes[b] += 1;
		}

		vector<int> counts;
		for (auto elem : clothes)
			counts.push_back(elem.second);

		answer = 0;
		allCombination(counts, counts.size());
		// for (int i = 0; i < counts.size(); i++) {
		// 	total += getMultipleComb(1, i+1, counts);
		// }
		cout << answer << endl;
	}

	return 0;
}