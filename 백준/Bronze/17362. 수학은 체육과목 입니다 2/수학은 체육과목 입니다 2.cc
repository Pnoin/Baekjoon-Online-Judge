#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = n % 8;
	if (m == 0 or m == 2) {
		cout << 2;
	}
	else if (m == 1) {
		cout << 1;
	}
	else if (m == 3 or m == 7) {
		cout << 3;
	}
	else if (m == 4 or m == 6) {
		cout << 4;
	}
	else if (m == 5) {
		cout << 5;
	}
}