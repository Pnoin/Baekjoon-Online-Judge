#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int s,t;

int Mul(int n){
    int cnt=0;
    for(int i=1; i<=n; i++){
        int a;
        if(i%2){
            a=-1;
        }
        else{
            a=1;
        }
        cnt+=(a*(n/i));
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;
    cout << Mul(t)-Mul(s-1);
} 