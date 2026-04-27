#include <iostream>
using namespace std;

int main() {
	int n, m, a[10005] = {};
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < m) {
			cout << a[i] << ' ';
		}
	}
}