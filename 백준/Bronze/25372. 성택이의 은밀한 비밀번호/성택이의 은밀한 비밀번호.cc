#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a.length() >= 6 and a.length() <= 9) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
}