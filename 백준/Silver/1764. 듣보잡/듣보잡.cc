#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector <string> v, name;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		name.push_back(s);
	}
	sort(name.begin(), name.end());
	for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		if (binary_search(name.begin(), name.end(), q)) {
			cnt++;
			v.push_back(q);
		}
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}