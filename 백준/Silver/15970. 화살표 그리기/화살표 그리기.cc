#include <iostream>
#include <algorithm>
#include <vector>
#pragma GCC optimize ("O3")
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, c[5005] = {};
	cin >> n;
	vector<vector<int>> v(n + 1); 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x); 
		c[y]++; 
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end()); 
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 0) {
			continue;
		}
		for (int j = 0; j < c[i]; j++) {
			if (j == 0) {
				cnt += v[i][1] - v[i][0];
			}
			else if (j == c[i] - 1) {
				cnt += v[i][c[i] - 1] - v[i][c[i] - 2];
			}
			else {
				cnt += min(v[i][j] - v[i][j - 1], v[i][j + 1] - v[i][j]);
			}
		}
	}
	cout << cnt;
}