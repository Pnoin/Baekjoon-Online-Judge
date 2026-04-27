#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, arr[15] = {}, visited[15] = {};
vector <int> v;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int nxt=0;
    for (int i = 0; i < n; i++) {
      if(visited[i]==0 and v[i]!=nxt){
        arr[cnt] = v[i]; 
        nxt=arr[cnt];
        visited[i]=1;
        dfs(cnt + 1);
        visited[i]=0; 
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
    dfs(0);
}