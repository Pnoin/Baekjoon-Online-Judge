#include <iostream>
#include <algorithm>
#include <vector>
#pragma GCC optimize ("O3")
using namespace std;

int arr[100005] = {};
int hi=1, lo=0, mn= 2000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(&arr[0], &arr[n]);
    while (true) {  
        if (hi == n) {
            break;
        }
        while (arr[hi] - arr[lo] >= m) {
            mn = min(mn, arr[hi] - arr[lo]);
            lo++;
        }
        hi++;
    }
    cout << mn;
}