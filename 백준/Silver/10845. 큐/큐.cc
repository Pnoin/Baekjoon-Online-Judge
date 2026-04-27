#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue <int> q;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		if (x == "push") {
			int y;
			cin >> y;
			q.push(y);
		}
		else if (x == "pop") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (x == "size") {
			cout << q.size() << "\n";
		}
		else if (x == "empty") {
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (x == "front") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (x == "back") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}