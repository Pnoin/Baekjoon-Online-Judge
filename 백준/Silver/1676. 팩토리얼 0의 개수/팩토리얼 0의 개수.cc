#include <iostream>
using namespace std;

int main() {
	long long n;
	int count = 0;
	cin >> n;
	for (int i = 5; i <= n; i *= 5) {
		count += n / i;
	}
	cout << count;
}
