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

int x,y,ans=1;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x >> y;
    for(int i=x; i<=y; i++){
        int total=0;
        for(int j=1; j<=i; j++){
            total+=j;
            total%=14579;
        }
        ans*=total;
        ans%=14579;
    }
    cout << ans;
}