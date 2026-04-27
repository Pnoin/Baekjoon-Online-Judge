#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[10005] = {}, arr[10] = {}, c[10] = {};

void solve(int cur) {
    if (cur == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) {
            continue;
        }
        c[i] = 1;
        arr[cur] = a[i];
        solve(cur + 1);
        c[i] = 0;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i]=i;
    }
    sort(&a[0], &a[n]);
    solve(0);
}