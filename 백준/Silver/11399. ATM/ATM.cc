#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, arr[1005] = {}, total = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; i++) {
		total += arr[i] * (n - i);
	}
	cout << total;
}