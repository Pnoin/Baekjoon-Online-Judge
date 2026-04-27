#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, arr[15] = {}, visited[15] = {};
vector <int> v;

void dfs(int num, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i < n; i++) {
        arr[cnt] = v[i];
        dfs(i, cnt + 1);
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    dfs(0, 0);
}