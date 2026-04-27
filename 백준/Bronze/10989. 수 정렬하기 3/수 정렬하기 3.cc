#include <iostream>
#include <algorithm>
using namespace std;

int cnt[10005] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, max=0, a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cnt[a]++;
		if (a >= max) {
			max = a;
		}
	}
	for (int i = 1; i <= max; i++) {
		for (int j = 1; j <=cnt[i]; j++) {
			cout << i << "\n";
		}
	}
}