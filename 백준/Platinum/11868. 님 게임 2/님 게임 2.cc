#include <iostream>
using namespace std;

int main() {
	int n, a[105] = {}, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	x = a[0];
	for (int i = 1; i < n; i++) {
		x = x ^ a[i];
	}
	if (x == 0) {
		cout << "cubelover";
	}
	else {
		cout << "koosaga";
	}
}