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

int n,cnt=1, mx=1, cur, prv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> prv;
    for(int i=1; i<n; i++){
        cin >> cur;
        if(cur>prv){
            cnt++;
        }
        else{
            cnt=1;
        }
        mx=max(mx,cnt);
        prv=cur;
    }
    cout << mx;
}