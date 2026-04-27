#include <iostream> 
using namespace std; 

int main() { 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cnt = i, total=i;
		while (cnt != 0){
			total += cnt % 10;
			cnt = cnt / 10;
		}
		if (total == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}

