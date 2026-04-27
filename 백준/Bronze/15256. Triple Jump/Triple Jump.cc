#include <algorithm>
#include <iostream>
#pragma GCC optimize ("03")
using namespace std;

double jump[2005] = {};

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cout << "Data Set " << i << ": " << '\n';
        int n;
        cin >> n;
        int start = -1;
        for (int i = 0; i < n; i++) {
            cin >> jump[i];
            if (start < 0 and jump[i] >= 30 and jump[i] <= 30.2) {
                start = i;
            }
        }
        if (start < 0 or start + 3 >= n) {
            cout << "0.00" << '\n' << '\n';
            continue;
        }
        double r = 1e100;
        for (int i = start + 3; i < n; i++) {
            r = min(r, jump[i]);
        }
        cout << fixed;
        cout.precision(2);
        cout << r - 30 << '\n' << '\n';
    }
}