#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c = 1;
	while (true) {
		int a;
		cin >> a;
		if (a == 0) {
			break;
		}
		for (int i = 0; i < a; i++) {
			int x;
			cin >> x;
		}
		cout << "Case " << c << ": Sorting... done!" << "\n";
		c++;
	}
}