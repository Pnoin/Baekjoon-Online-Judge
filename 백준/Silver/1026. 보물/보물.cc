#include <iostream>
#include <algorithm>
using namespace std;

int a[55] = {}, b[55] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(&a[0], &a[n]);
	sort(&b[0], &b[n], greater<>());
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i] * b[i];
	}
	cout << total;
}