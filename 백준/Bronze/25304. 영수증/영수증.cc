#include <iostream>
using namespace std;

int main() {
    int x, t, a, b, total = 0;
    cin >> x >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        total += a * b;
    }

    if (total == x) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}