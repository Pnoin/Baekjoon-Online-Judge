#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;

int a,b,c,d,e,total=0,ans=0,cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c >> d >> e;
    if(b+d>c){
        cout << -1;
        return 0;
    }
    total=b;
    while(true){
        if(ans>=a){
            break;
        }
        while(true){
            if(total+d<=c){
                break;
            }
            total-=e;
            cnt++;
            if(b>=total){
                total=b;
            }
        }
        total+=d;
        ans++;
    }
    cout << ans+cnt;
}