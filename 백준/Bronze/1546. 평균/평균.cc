#include <iostream>
using namespace std;

int main() {
	int n, num[1005] = {}, max = 0;
	cin >> n;
	float mean=0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (num[i] > max) {
			max = num[i];
		}
	}
	for (int i = 0; i < n; i++) {
		mean += float(num[i]) / max * 100;
	}
	mean = mean / n;
	cout << mean;
}