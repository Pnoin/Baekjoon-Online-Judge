#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q, a, b, c;
    cin >> q;
    for(int i=0; i<q; i++){
    	cin >> a >> b >> c;
    	cout << min(a, min(b, c)) << '\n';
	}
}