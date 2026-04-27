#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,m,a[500005]={},num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        if(binary_search(a,a+n,num)){
            cout << 1 << ' ';
        }
        else{
            cout << 0 << ' ';
        }
    }
}