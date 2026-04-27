#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double l, a, b, c, d, total = 0;
	cin >> l >> a >> b >> c >> d;
	total = max(ceil(a / c), ceil(b / d));
	cout << l - total;
}