#include <iostream> 
using namespace std; 

int main() { 
	int n, total = 1, cnt = 1;
	cin >> n;
	while (n > total) {
		total += 6 * cnt;
		cnt++;
	}
	cout << cnt;
}

