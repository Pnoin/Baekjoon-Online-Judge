#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, a;
    cin >> n;
    a = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a -= a / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        a -= a / n;
    }
    cout << a;
}
