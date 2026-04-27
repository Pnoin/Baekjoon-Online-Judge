#include <iostream>
#include <algorithm>
using namespace std;

int num(int x, int y) {
	int sum = 0;
	if (y == 1) {
		return 1;
	}
	if (x == 0) {
		return y;
	}
	for (int i = 1; i <= y; i++) {
		sum += num(x - 1, i);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, k, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << num(k, n) << "\n";
	}
}
