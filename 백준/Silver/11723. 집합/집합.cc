#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, arr[25] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			int x;
			cin >> x;
			arr[x] = 1;
		}
		else if (s == "remove") {
			int x;
			cin >> x;
			arr[x] = 0;
		}
		else if (s == "check") {
			int x; 
			cin >> x;
			cout << arr[x] << '\n';
		}
		else if (s == "toggle") {
			int x;
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
			else {
				arr[x] = 1;
			}
		}
		else if (s == "all") {
			for (int j = 1; j <= 20; j++) {
				arr[j] = 1;
			}
		}
		else if (s == "empty") {
			for (int j = 1; j <= 20; j++) {
				arr[j] = 0;
			}
		}
	}
}