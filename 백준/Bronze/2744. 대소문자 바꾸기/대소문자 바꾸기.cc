#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 and s[i] <= 90) {
			s[i] = s[i] + 32;
		}
		else {
			s[i] = s[i] - 32;
		}
	}
	cout << s;
}