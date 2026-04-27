#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector <long long int> v;
		v.push_back(0);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		for (int i = 6; i <= n; i++) {
			long long int x = v[i - 1] + v[i - 5];
			v.push_back(x);
		}
		cout << v[n] << '\n';
	}
}