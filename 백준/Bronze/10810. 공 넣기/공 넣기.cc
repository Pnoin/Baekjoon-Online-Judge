#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> pll;

int n,m,arr[105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        for(int j=x; j<=y; j++){
            arr[j]=z;
        }
    }
    for(int i=1; i<=n; i++){
        cout << arr[i] << ' ';
    }
}