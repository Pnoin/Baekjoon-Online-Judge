#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> pll;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int mnx=100000,mny=100000,mxx=-100000,mxy=-100000;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        mnx=min(mnx,x);
        mny=min(mny,y);
        mxx=max(mxx,x);
        mxy=max(mxy,y);
    }
    cout << (mxx-mnx)*(mxy-mny);
}