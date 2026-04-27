#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[100005] = {}, num;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(&arr[0], &arr[n]);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (binary_search(&arr[0], &arr[n], num)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}

