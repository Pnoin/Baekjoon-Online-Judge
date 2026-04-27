#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string arr[13] = { "4.3", "4.0", "3.7", "3.3", "3.0", "2.7", "2.3", "2.0", "1.7", "1.3", "1.0", "0.7", "0.0" };
	string s[13] = { "A+", "A0", "A-", "B+", "B0", "B-","C+", "C0", "C-", "D+", "D0", "D-", "F" };
	string a;
	cin >> a;
	for (int i = 0; i < 13; i++) {
		if (s[i] == a) {
			cout << arr[i];
			return 0;
		}
	}
}