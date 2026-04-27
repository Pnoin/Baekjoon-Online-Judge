#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map <string, string> p;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		p[a] = b;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << p[s] << '\n';
	}
}