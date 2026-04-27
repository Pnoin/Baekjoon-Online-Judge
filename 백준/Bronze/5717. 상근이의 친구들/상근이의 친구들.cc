#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 and m == 0) {
			break;
		}
		cout << n + m << '\n';
	}
}