#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string arr[100005] = {};
map <string, int> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		arr[i] = s;
		p.insert(make_pair(s, i));
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s[0] >= 65 and s[0] <= 90) {
			cout << p[s] << '\n';
		}
		else {
			int y = stoi(s);
			cout << arr[y] << '\n';
		}
	}
}