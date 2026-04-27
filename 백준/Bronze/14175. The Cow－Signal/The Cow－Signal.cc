#include <iostream>
#include <string>
using namespace std;

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	char arr[15][15] = {};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int q = 0; q < k; q++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < k; l++) {
					cout << arr[i][j];
				}
			}
			cout << "\n";
		}
	}
}