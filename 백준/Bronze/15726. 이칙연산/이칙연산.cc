#include <iostream>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	if (a * b / c > a / b * c) {
		cout << (int)(a * b / c);
	}
	else {
		cout << (int)(a / b * c);
	}
}