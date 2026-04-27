#include <iostream>
using namespace std;

int main() {
	int n, m, arr[105] = {}, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < n; i++) {
		if (m == arr[i]) {
			ans++;
		}
	}
	cout << ans;
}