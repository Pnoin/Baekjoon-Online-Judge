#include <iostream> 
#include <string>
using namespace std; 

int main() { 
	int n;
	cin >> n;
	long long int a = 665;
	while (n > 0) {
		a++;
		string s = to_string(a);
		for (int i = 0; i < s.size() - 2; i++) {
			if (s[i] == '6' and s[i + 1] == '6' and s[i + 2] == '6') {
				n--;
				break;
			}
		}
	}
	cout << a;
}

