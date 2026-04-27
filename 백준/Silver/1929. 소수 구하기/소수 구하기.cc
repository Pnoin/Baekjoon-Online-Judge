#include <iostream>
using namespace std;

int a[1000005] = {};

int main() {
    int m, n;
    cin >> m >> n;
    int total = 0;
    for (int i = 2; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            continue;
        }
        for (int j = 2 * i; j <= n; j += i) {
            a[j] = 0;
        }
    }
    for (int i = m; i <= n; i++) {
        if (a[i] != 0) {
            cout << a[i] << "\n";
        }
    }
}