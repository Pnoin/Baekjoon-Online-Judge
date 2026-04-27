#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int x = 0;
	while (true) {
		if (q.size() == 1) {
			x = q.front();
			break;
		}
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << x;
}