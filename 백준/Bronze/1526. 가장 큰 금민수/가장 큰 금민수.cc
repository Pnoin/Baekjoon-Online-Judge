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

int n,mx=0;

bool ck(int x){
    while(true){
        if(x==0){
            break;
        }
        if(x%10!=4 && x%10!=7){
            return false;
        }
        x/=10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=4; i<=n; i++){
        if(ck(i)){
            mx=max(mx,i);
        }
    }
    cout << mx;
}