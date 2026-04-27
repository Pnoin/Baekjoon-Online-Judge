#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, arr[15][3000005] = {}, we[15] = {};

void solve(int start, int w) {
	if (start > n or arr[start][w] == 1) {
		return;
	}
	arr[start][w] = 1;
	solve(start + 1, w + we[start]);
	solve(start + 1, abs(w - we[start]));
	solve(start + 1, w);
}

int main() {
	int sum = 0, total = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> we[i];
		sum += we[i];
	}
	solve(0, 0);
	for (int i = 1; i <= sum; i++) {
		if (arr[n][i] != 1) {
			total++;
		}
	}
	cout << total;
}