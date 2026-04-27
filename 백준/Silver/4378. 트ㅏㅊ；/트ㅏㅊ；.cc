#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string k = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	while (true) {
		string s;
		getline(cin, s);
		if (s == "") {
			break;
		}
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < k.size(); j++) {
				if (s[i] == ' ') {
					cout << ' ';
					break;
				}
				if (s[i] == k[j]) {
					cout << k[j - 1];
					break;
				}
			}
		}
		cout << '\n';
	}
}