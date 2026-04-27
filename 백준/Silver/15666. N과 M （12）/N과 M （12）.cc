#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <complex>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;
const double PI = acos(-1);
typedef complex<double> cpx;

int n, m, arr[15] = {}, visited[15] = {};
vector <int> v;

void dfs(int cnt, int x) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int nxt=0;
    for (int i = x; i < n; i++) {
      if(v[i]!=nxt){
        arr[cnt] = v[i]; 
        nxt=arr[cnt];
        dfs(cnt + 1, i);
      }
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
    dfs(0,0);
}