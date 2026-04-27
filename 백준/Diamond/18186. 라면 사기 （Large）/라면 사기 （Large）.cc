#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[1000005] = {}, n, a, b, x, y, total = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (x > y) {
        for (int i = 0; i < n; i++) {
            if (arr[i + 1] > arr[i + 2]) {
                a = min(arr[i], arr[i + 1] - arr[i + 2]);
                total += (x + y) * a;
                arr[i] -= a;
                arr[i + 1] -= a;
                b = min(arr[i], min(arr[i + 1], arr[i + 2]));
                total += (x + (y * 2)) * b;
                arr[i] -= b;
                arr[i + 1] -= b;
                arr[i + 2] -= b;
            }
            else {
                a = min(arr[i], min(arr[i + 1], arr[i + 2]));
                total += (x + (y * 2)) * a;
                arr[i] -= a;
                arr[i + 1] -= a;
                arr[i + 2] -= a;
                b = min(arr[i], arr[i + 1]);
                total += (x + y) * b;
                arr[i] -= b;
                arr[i + 1] -= b;
            }
            total += x * arr[i];
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            total += x * arr[i];
        }
    }
    cout << total;
}