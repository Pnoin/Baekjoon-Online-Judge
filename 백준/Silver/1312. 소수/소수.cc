#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, n, v = 0;
	cin >> a >> b >> n;
	for (int i = 0; i <= n; i++) {
		v = a / b;
		a = a % b * 10;
	}
	cout << v;
}