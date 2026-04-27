#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[100][100] = {}, b[100][100] = {}, n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] += b[i][j];
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}