#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue <int> que;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	cout << '<';
	while (que.empty() == false) {
		for (int i = 0; i < k - 1; i++) {
			que.push(que.front());
			que.pop();
		}
		cout << que.front();
		que.pop();
		if (que.empty()==false) {
			cout << ", ";
		}
	}
	cout << '>';
}