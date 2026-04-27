#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[5] = {};
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	sort(&arr[0], &arr[3]);
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}
}