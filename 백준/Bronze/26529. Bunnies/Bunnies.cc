#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;

int n,arr[50]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arr[0]=1;
    arr[1]=1;
    for(int i=2; i<=45; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        cout << arr[num] << '\n';
    }
}