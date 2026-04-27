#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int nume = 1, deno = 1;
	for (int i = 1; i <= n; i++) {
		nume *= i;
	}
	for (int i = 1; i <= k; i++) {
		deno *= i;
	}
	for (int i = 1; i <= n - k; i++) {
		deno *= i;
	}
	cout << nume / deno;
}