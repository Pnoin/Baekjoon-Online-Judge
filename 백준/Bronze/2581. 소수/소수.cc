#include <iostream>
using namespace std;


int main() {
	int m, n, count=0, sum=0, min=100000000;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				count++;
			}
		}
		if (count == 2) {
			sum += i;
			if (i < min) {
				min = i;
			}
		}
	}
	if (sum == 0) {
		cout << "-1";
	}
	else {
		cout << sum << "\n" << min;
	}
}