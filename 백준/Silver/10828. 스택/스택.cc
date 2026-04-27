#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack <int> q;
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
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else if (x == "size") {
			cout << q.size() << "\n";
		}
		else if (x == "empty") {
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (x == "top") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.top() << "\n";
			}
		}
	}
}