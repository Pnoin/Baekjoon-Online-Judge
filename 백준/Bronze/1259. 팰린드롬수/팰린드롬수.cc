#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector <string> v;
	string n;
	while (true) {
		cin >> n;
		if (n == "0") {
			break;
		}
		else {
			v.push_back(n);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int temp = 0;
		if (v[i].size() % 2 == 1) {
			for (int j = 0; j < (v[i].size() - 1) / 2; j++) {
				if (v[i][j] != v[i][v[i].size() - j - 1]) {
					temp = 1;
					break;
				}
			}
			if (temp == 1) {
				cout << "no" << "\n";
			}
			else {
				cout << "yes" << "\n";
			}
		}
		else {
			for (int j = 0; j < v[i].size() / 2; j++) {
				if (v[i][j] != v[i][v[i].size() - j - 1]) {
					temp = 1;
					break;
				}
			}
			if (temp == 1) {
				cout << "no" << "\n";
			}
			else {
				cout << "yes" << "\n";
			}
		}
	}
}