#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[15] = {}, visited[15] = {};

void dfs(int num, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    dfs(1, 0);
}