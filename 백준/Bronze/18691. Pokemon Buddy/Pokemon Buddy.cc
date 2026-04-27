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

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        int a,b,c;
        cin >> a >> b >> c;
        c-=b;
        if(c<=0){
            cout << 0 << '\n';
            continue;
        }
        if(a==1){
            cout << c << '\n';
        }
        else if(a==2){
            cout << c*3 << '\n';
        }
        else if(a==3){
            cout << c*5 << '\n';
        }
    }
}