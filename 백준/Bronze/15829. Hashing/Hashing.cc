#include <iostream> 
#include <string>
using namespace std; 

int main() { 
	int n;
	string s;
	cin >> n >> s;
	long long int total = 0, m=1234567891;
	for (int i = 0; i < s.size(); i++) {
		long long x = 1;
		for (int j = 1; j <= i; j++) {
			x *= 31;
			if (x > m) {
				x %= m;
			}
		}
		total += (s[i] - 96) * x;
		if (total > m) {
			total %= m;
		}
	}
	cout << total;
}

