#include <iostream>
using namespace std;

int arr[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j or j == 0) {
                arr[i][j] = 1;
            }
            else
                arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
        }
    }
    cout << arr[n][k];
}