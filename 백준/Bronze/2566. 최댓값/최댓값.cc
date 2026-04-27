#include <iostream>
using namespace std;

int main() {
	int arr[90][90] = {}, mx = 0, x = 0, y = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= mx) {
				mx = arr[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << mx << "\n" << x << ' ' << y;
}