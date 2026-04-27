#include <iostream>
#include <algorithm>
using namespace std;

long long int a[1000005] = {}, cnt = 0;

void solve(long long int x, long long int y) {
    for (long long int i = 2; i * i <= y; i++) {
        long long int q = x / (i * i);
        if (x % (i * i) != 0) {
            q++;
        }
        while (true) {
            if (q * i * i > y) {
                break;
            }
            a[q * (i * i) - x] = 1;
            q++;
        }
    }
    for (long long int i = 0; i <= y - x; i++) {
        if (a[i] == 0) {
            cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n,m;
    cin >> n >> m;
    solve(n,m);
    cout << cnt;
}