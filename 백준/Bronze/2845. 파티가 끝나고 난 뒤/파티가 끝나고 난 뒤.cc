#include <iostream>
using namespace std;

int main(){
	int a, b, c = 0, arr[10] = {};
	cin >> a >> b;
	c = a * b;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] > c) {
			cout << arr[i] - c << ' ';
		}
		else if (arr[i] < c) {
			cout << '-' << c - arr[i] << ' ';
		}
		else if (arr[i] == c) {
			cout << '0' << ' ';
		}
	}
}