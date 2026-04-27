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
typedef long double ld;
typedef complex<double> cpx;

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        int n,mx=-1e9,cur=0;
        cin >> n >> cur;
        mx=max(mx,cur);
        for(int j=1; j<n; j++){
            int num;
            cin >> num;
            cur=max(cur+num,num);
            mx=max(mx,cur);
        }
        cout << mx << '\n';
    }   
}