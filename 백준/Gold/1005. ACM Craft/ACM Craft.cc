#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,m,visit[1005]={},t,cost[1005]={},total[1005]={},fin;
vector<int> v[1005];

void topology(){
    vector<int> ans;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(visit[i]==0){
            q.push(i);
            total[i]=cost[i];
        }
    }
    for(int i=1; i<=n; i++){
        if(q.empty()){
            return;
        }
        ans.push_back(q.front());
        for(int j=0; j<v[q.front()].size(); j++){
            total[v[q.front()][j]]=max(total[v[q.front()][j]],total[q.front()]+cost[v[q.front()][j]]);
            visit[v[q.front()][j]]--;
            if(visit[v[q.front()][j]]==0){
                q.push(v[q.front()][j]);
            }
        }
        q.pop();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        memset(visit,0,sizeof(visit));
        memset(total,0,sizeof(total));
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            v[i].clear();
        }
        for(int i=1; i<=n; i++){
            cin >> cost[i];
        }
        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            visit[y]++;
        }
        cin >> fin;
        topology();
        cout << total[fin] << '\n';
    }
}