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

int n,a,b,c,d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b >> c >> d;
    int cnta=1,cntc=1,tempa=a,tempc=c;
    while(true){
        if(tempa>=n){
            break;
        }
        tempa+=a;
        cnta++;
    }
    while(true){
        if(tempc>=n){
            break;
        }
        tempc+=c;
        cntc++;
    }
    cout << min(cnta*b,cntc*d);
} 