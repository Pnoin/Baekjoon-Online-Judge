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

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cout << "Scenario #" << i << ":" << '\n';
        int a,b,c;
        cin >> a >> b >> c;
        if(a*a + b*b + c*c - 2*(max(max(a,b),c)*max(max(a,b),c))==0){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
        cout << '\n';
    }  
} 