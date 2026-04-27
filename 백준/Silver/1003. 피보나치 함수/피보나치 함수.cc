#include <iostream>
using namespace std;

int a[50] = {};

int fibonacci(int n) {
    if (n == 0) {
        a[0] = 0;
        return 0;
    }
    else if (n == 1) {
        a[1] = 1;
        return 1;
    }
    if (a[n] != 0) {
        return a[n]; 
    } 
    else {
        return a[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x; 
    for (int i = 0; i < x; i++) {
        int m;
        cin >> m;
        if (m == 0) {
            cout << 1 << ' ' << 0 << "\n";
        }
        else if (m == 1) {
            cout << 0 << ' ' << 1 << "\n";
        }
        else {
            fibonacci(m);
            cout << a[m - 1] << ' ' << a[m] << "\n";
        }
    }
}