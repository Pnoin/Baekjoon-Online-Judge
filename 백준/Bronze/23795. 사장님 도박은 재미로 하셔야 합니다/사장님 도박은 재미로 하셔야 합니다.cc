#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int total = 0;
	while (true) {
		int x;
		cin >> x;
		if (x == -1) {
			break;
		}
		total += x;
	}
	cout << total;
}