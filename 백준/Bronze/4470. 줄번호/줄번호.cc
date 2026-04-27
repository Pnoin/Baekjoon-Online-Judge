#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		cin.clear();
		cout << i << ". " << s << '\n';
	}
}