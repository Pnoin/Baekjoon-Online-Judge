#include <iostream>
using namespace std;

int main() {
	int m, total=0;
	cin >> m;
	char a[105] = {};
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		total += a[i] - '0';
	}
	cout << total;
}