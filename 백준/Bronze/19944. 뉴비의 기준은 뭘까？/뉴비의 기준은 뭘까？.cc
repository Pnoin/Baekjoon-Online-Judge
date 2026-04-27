#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (m == 1 or m == 2) {
		cout << "NEWBIE!";
	}
	else {
		if (m <= n) {
			cout << "OLDBIE!";
		}
		else {
			cout << "TLE!";
		}
	}
}