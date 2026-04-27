#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		int q = 0, w = 0, temp = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '(') {
				q++;
			}
			else if (a[i] == ')') {
				w++;
			}
			if (w > q) {
				cout << "NO" << "\n";
				temp = 1;
				break;
			}
		}
		if (temp == 0) {
			if (q == w) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}
}