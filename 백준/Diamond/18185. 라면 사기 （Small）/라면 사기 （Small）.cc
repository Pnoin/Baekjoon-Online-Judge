#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, total = 0, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if(arr[i + 1] > arr[i + 2]) {
            a = min(arr[i], arr[i + 1] - arr[i + 2]);
            total += 5 * a;
            arr[i] -= a;
            arr[i + 1] -= a;
            b = min(arr[i], min(arr[i + 1], arr[i + 2]));
            total += 7 * b;
            arr[i] -= b;
            arr[i + 1] -= b;
            arr[i + 2] -= b;
            
        }
        else {
            a = min(arr[i], min(arr[i + 1], arr[i + 2]));
            total += 7 * a;
            arr[i] -= a;
            arr[i + 1] -= a;
            arr[i + 2] -= a;
            b = min(arr[i], arr[i + 1]);
            total += 5 * b;
            arr[i] -= b;
            arr[i + 1] -= b;
        }
        total += 3 * arr[i];
    }
    cout << total;
}