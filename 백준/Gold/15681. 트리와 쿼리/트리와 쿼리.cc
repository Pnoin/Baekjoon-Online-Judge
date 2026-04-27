#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const long double PI = acos(-1); 

int n,r,q,dp[100005]={};
vector <int> v[100005];
bool visit[100005]={};

void parent_check(int cur){
    visit[cur]=true;
    for(int i=0; i<v[cur].size(); i++){
        if(visit[v[cur][i]]){
            v[cur][i]=-1;
        }
        else{
            parent_check(v[cur][i]);
        }
    }
}

void dfs(int cur){
    dp[cur]=1;
    for(int i=0; i<v[cur].size(); i++){
        if(v[cur][i]==-1){
            continue;
        }
        dfs(v[cur][i]);
        dp[cur]+=dp[v[cur][i]];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> q;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    parent_check(r);
    dfs(r);
    for(int i=0; i<q; i++){
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }
}