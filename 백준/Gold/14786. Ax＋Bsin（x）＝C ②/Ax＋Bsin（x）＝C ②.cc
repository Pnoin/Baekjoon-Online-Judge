#include <iostream>
#include <cmath>
using namespace std;

long double bs(int x, int y, int z) {
	long double eps = 0.0000000001, mn=0, mx=250000, med = (mx + mn) / 2;
	while (mx-mn>eps) {
		med = (mx + mn) / 2;
		if ((x * med) + (y * sin(med)) > z) {
			mx = med;
		}
		else if ((x * med) + (y * sin(med)) < z) {
			mn = med;
		}
	}
	return med; 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout.precision(10);
	cout << bs(a, b, c);
}