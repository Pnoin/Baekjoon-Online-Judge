#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, a, total=0, x;
	stack <int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			s.pop();
		}
		else {
			s.push(a);
		}
	}
	x = s.size();
	for (int i = 0; i < x; i++) {
		total += s.top();
		s.pop();
	}
	cout << total;
}