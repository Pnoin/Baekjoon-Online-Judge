#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int c = n, v = 0;
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < v; j++) {
			cout << ' ';
		}
		for (int j = 0; j < c; j++) {
			cout << '*';
		}
		cout << "\n";
		c--;
		v++;
	}
}