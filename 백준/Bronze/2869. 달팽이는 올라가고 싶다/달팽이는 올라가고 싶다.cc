#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, v;
	cin >> a >> b >> v;
	int one = a - b, yeah = v - b - 1, h = ceil(yeah / one);
	cout << h+1;
}