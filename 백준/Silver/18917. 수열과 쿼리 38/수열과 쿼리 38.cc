#include <iostream>
using namespace std;

int  main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m,q;
	cin >> m;
	long long x, total=0, y=0;
	for (int i = 0; i < m; i++) {
		cin >> q;
		if (q == 1) {
			cin >> x;
			total += x;
			y ^= x;
		}
		else if (q == 2) {
			cin >> x;
			total -= x;
			y ^= x;
		}
		else if (q == 3) {
			cout << total << "\n";
		}
		else if (q == 4) {
			cout << y << "\n";
		}
	}
}