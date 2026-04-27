#include <iostream>
#include <algorithm>
using namespace std;

int n, total = 0, score[10005] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	sort(&score[0], &score[n]);
	for (int i = 0; i < n; i++) {
		total += score[i];
		if (total < i * (i + 1) / 2) {
			cout << "-1";
			return 0;
		}
	}
	cout << (total == n * (n - 1) / 2 ? 1 : -1);
}