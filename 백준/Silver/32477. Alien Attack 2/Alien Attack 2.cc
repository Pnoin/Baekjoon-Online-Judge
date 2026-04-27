#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <numeric>
#include <set>
#include <map>
#include <regex>
#include <deque>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

int n,m,p[200005]={},sz[200005]={},ans=0;

int findset(int x){
    while(p[x]!=x){
        p[x]=p[p[x]];
        x=p[x];
    }
    return x;
}

void unionset(int a,int b){
    a=findset(a);
    b=findset(b);
    if(a==b){
        return;
    }
    if(sz[a]<sz[b]){
        int t=a;
        a=b;
        b=t;
    }
    p[b]=a;
    sz[a]+=sz[b];
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        p[i]=i;
        sz[i]=1;
    }
    for(int i=0; i<m; i++){
        int q,w;
        cin >> q >> w;
        unionset(q,w);
    }
    for(int i=1; i<=n; i++){
        int r=findset(i);
        if(ans<sz[r]){
            ans=sz[r];
        }
    }
    cout << ans;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

