#include <iostream>
using namespace std;

int main() {
	int k, d, a;
	char slash;
	cin >> k >> slash >> d >> slash >> a;
	if (d==0) {
		cout << "hasu";
	}
	else {
		if ((k + a) / d > 0) {
			cout << "gosu";
		}
		else {
			cout << "hasu";
		}
	}
}