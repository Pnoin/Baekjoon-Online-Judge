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
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout <<'@';
            }
            cout << '\n';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<5*n; j++){
            cout << '@';
        }
        cout << '\n';
    }
} 