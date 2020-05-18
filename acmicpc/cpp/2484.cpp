#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int maxValue = -1;
	for (int i = 0; i < n; i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int value = 0;
		if (a==b && b==c && c==d) {
			value = 50000 + 5000*a;
		} 
		
		// 3
		else if ((a==b && b==c) || (b==c && c==d)) {
			value = 10000 + 1000*c;
		} else if ((a==c && c==d) || (a==b && b==d)) {
			value = 10000 + 1000*a;
		} 
		
		// 2 2
		else if ((a==b && c==d) || (a==c && b==d) || (a==d && b==c)) {
			value = 2000+500*(a+b+c+d)/2;
		}
		
		// 2
		else if (a==b) {
			value = 1000+100*a;
		} else if (a==c) {
			value = 1000+100*a;
		} else if (a==d) {
			value = 1000+100*a;
		} else if (b==c) {
			value = 1000+100*b;
		} else if (b==d) {
			value = 1000+100*b;
		} else if (c==d) {
			value = 1000+100*c;
		}
		
		else {
			value = 100*max(a,max(b,max(c,d)));
		}
		//cout << value << endl;
		maxValue = max(maxValue, value);
	}
	cout << maxValue << endl;
	return 0;
}