#include <iostream>
using namespace std;

int main() {
	int a, b, c, t;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> a >> b;
		c = a % 10; 
		if(b > 1){
			for (int j = 2; j <= b; j++) {
				c = (c * a) % 10;
			}
		}
		if (c == 0) {
			cout << 10 << '\n';
		}
		else {
			cout << c << '\n';
		}
	}
}