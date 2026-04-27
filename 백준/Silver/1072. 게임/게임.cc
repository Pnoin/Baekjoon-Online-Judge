#include <iostream>
using namespace std;

int bs(long long w, long long e) {
    int mx = 1000000000, mn = 0, cnt = 0;
    while (mn <= mx) {
        int med = (mx + mn) / 2, temp = ((e + med) * 100 / (w + med));
        if (e * 100 / w >= temp) {
            cnt = med + 1;
            mn = med + 1;
        }
        else {
            mx = med - 1;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long x, y;
    cin >> x >> y;
    if (y * 100 / x >= 99) {
        cout << "-1";
    }
    else {
        cout << bs(x, y);
    }
}