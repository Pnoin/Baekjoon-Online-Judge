#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n >= 3 and m <= 4) {
		cout << "TroyMartian" << '\n';
	}
	if (n <= 6 and m >= 2) {
		cout << "VladSaturnian" << '\n';
	}
	if (n <= 2 and m <= 3) {
		cout << "GraemeMercurian" << '\n';
	}
}