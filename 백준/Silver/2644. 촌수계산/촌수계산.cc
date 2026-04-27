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

int n,x,y,m,ans=-1,visit[105]={};
vector <int> adj[105];

void dfs(int num, int cur){
    visit[num]=1;
    if(num==y){
        ans=cur;
        return;
    }
    for(int i=0; i<adj[num].size(); i++){
        if(visit[adj[num][i]]==0){
            dfs(adj[num][i],cur+1);
        }
    }
    visit[num]=0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x >> y >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(x,0);
    cout << ans;
}