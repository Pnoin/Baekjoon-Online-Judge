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

int n,x,y,mn=2e9,ck=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        if(x<=y){
            mn=min(mn,y);
            ck=1;
        }
    }
    if(ck==0){
        cout << -1;
    }
    else{
        cout << mn;
    }
}