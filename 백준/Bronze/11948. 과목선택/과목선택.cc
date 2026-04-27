#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[10] = {}, b[10] = {}, total = 0;
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> b[i];
    }

    sort(&a[0], &a[4]);
    sort(&b[0], &b[2]);

    for (int i = 1; i < 4; i++) {
        total += a[i];
    }
    total += max(b[0], b[1]);

    cout << total;
}