#include <iostream>
using namespace std;

int main() {
	while (true) {
		string name;
		int a, m;
		cin >> name >> a >> m;
		if (name == "#" and a == 0 and m == 0) {
			break;
		}
		if (a > 17 or m >= 80) {
			cout << name << ' ' << "Senior" << "\n";
		}
		else {
			cout << name << ' ' << "Junior" << "\n";
		}
	}
}