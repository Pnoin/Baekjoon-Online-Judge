#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, arr[15] = {};
	vector <int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > k) {
			break;
		}
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end(), greater<>());
	int i = 0, cnt = 0;
	while (k != 0) {
		cnt += k / v[i];
		k %= v[i];
		i++;
	}
	cout << cnt;
}