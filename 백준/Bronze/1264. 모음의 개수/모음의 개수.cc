#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		string s;
		int total = 0;
		getline(cin, s);
		if (s == "#") {
			break;
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') {
				total++;
			}
			if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U') {
				total++;
			}
		}
		cout << total << '\n';
	}
	
}