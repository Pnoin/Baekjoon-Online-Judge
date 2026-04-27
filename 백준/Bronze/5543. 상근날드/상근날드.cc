#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int q, w, e, r, t;
	cin >> q >> w >> e >> r >> t;
	cout << min(min(q, w), e) + min(r, t) - 50;
}