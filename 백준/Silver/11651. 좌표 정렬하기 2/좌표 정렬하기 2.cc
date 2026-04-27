#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	pair <int, int> a[100005];
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(&a[0], &a[n]);
	for (int i = 0; i < n; i++) {
		cout << a[i].second << ' ' << a[i].first << "\n";
	}
}