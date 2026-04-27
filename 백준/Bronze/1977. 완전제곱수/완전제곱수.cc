#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	vector <int> v;
	for (int i = 1; i <= 100; i++) {
		int x = i * i;
		v.push_back(x);
	}
	int ck = 0, sma = 0;
	for (int i = n; i <= m; i++) {
		if (binary_search(v.begin(), v.end(), i)) {
			cnt += i;
			if (ck == 0) {
				sma = i;
				ck = 1;
			}
		}
	}
	if (cnt == 0) {
		cout << -1; 
		return 0;
	}
	cout << cnt << '\n' << sma;
}