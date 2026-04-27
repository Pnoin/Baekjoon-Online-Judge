#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b) {
		if (b == c) {
			cout << a * 1000 + 10000;
		}
		else {
			cout << a * 100 + 1000;
		}
	}
	else if(b == c) {
		if (a == b) {
			cout << b * 1000 + 10000;
		}
		else {
			cout << b * 100 + 1000;
		}
	}
	else if(a == c) {
		if (b == c) {
			cout << a * 1000 + 10000;
		}
		else {
			cout << a * 100 + 1000;
		}
	}
	else {
		cout << max(max(a, b), c) * 100;
	}
}