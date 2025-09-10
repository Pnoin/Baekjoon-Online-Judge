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

int n,m,k,ck;
ll x,y,tree[2000005]={};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */

	cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> x;
        tree[i+n]=x; 
    }
    for(int i=n-1; i>0; i--){
        tree[i]=tree[i*2]+tree[i*2+1];
    }
    for(int i=0; i<m+k; i++){
        cin >> ck >> x>> y;
        if(ck==1){
            tree[x+n-1]=y;
            for(int idx=(x+n-1)>>1; idx; idx>>=1){
                tree[idx]=tree[idx*2]+tree[idx*2+1];
            }
        }
        else if(ck==2){
            ll total=0;
            for(int l=x+n-1,r=y+n; l<r; l>>=1,r>>=1){
                if(l%2){
                    total+=tree[l++];
                }
                if(r%2){
                    total+=tree[--r];
                }
            }
            cout << total << '\n';
        }
    }
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   