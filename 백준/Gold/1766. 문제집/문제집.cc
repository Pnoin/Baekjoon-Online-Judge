#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,m,visit[32005]={};
vector <int> v[32005];

void topology(){
    vector <int> ans;
    priority_queue <int,vector<int>,greater<int>> q;
    for(int i=1; i<=n; i++){
        if(visit[i]==0){
            q.push(i);
        }
    }
    for(int i=1; i<=n; i++){
        if(q.empty()){
            return;
        }
        ans.push_back(q.top());
        int temp=q.top();
        q.pop();
        for(int j=0; j<v[temp].size(); j++){
            visit[v[temp][j]]--;
            if(visit[v[temp][j]]==0){
                q.push(v[temp][j]);
            }
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        visit[y]++;
        x=y;
    }
    topology();
}