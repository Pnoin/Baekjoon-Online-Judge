#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[15] = {}, c = 0;
	cin >> n;
	while (n != 0) {
		arr[c] = n % 10;
		n /= 10;
		c++;
	}
	sort(&arr[0], &arr[c+1], greater<>());
	for (int i = 0; i < c; i++) {
		cout << arr[i];
	}
}