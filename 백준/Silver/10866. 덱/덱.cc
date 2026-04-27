#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main() {
	int n;
	cin >> n;
	deque <int> q;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		if (x == "push_front") {
			int y;
			cin >> y;
			q.push_front(y);
		}
		else if (x == "push_back") {
			int y;
			cin >> y;
			q.push_back(y);
		}
		else if (x == "pop_front") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (x == "pop_back") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
				q.pop_back();
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