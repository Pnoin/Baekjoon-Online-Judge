#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int cnt = 0;
		while (true) {
			if (n < 25) {
				break;
			}
			n -= 25;
			cnt++;
		}
		cout << cnt << ' ';
		cnt = 0;
		while (true) {
			if (n < 10) {
				break;
			}
			n -= 10;
			cnt++;
		}
		cout << cnt << ' ';
		cnt = 0;
		while (true) {
			if (n < 5) {
				break;
			}
			n -= 5;
			cnt++;
		}
		cout << cnt << ' ';
		cnt = 0;
		while (true) {
			if (n < 1) {
				break;
			}
			n -= 1;
			cnt++;
		}
		cout << cnt << ' ' << '\n';
	}
}