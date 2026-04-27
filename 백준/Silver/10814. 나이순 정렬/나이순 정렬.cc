#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

pair <int, string> a[100005];

bool compare(pair <int, string> a, pair <int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	stable_sort(&a[0], &a[n], compare);
	for (int i = 0; i < n; i++) {
		cout << a[i].first << ' ' << a[i].second << "\n";
	}
}