#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[500005] = {}, b[500005] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(&a[0], &a[n]);
	for (int i = 0; i < m; i++) {
		cout << upper_bound(&a[0], &a[n], b[i]) - lower_bound(&a[0], &a[n], b[i]) << ' ';
	}
}
