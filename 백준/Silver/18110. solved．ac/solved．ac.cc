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

int n,arr[300005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    if(n==0){
        cout << 0;
        return 0;
    }
    sort(arr,arr+n);
    ld total=0,temp=n-(round((ld)n*15/100)*2);
    for(int i=(int)round((ld)n*15/100); i<n-(int)round((ld)n*15/100); i++){
        total+=arr[i];
    }
    cout << round(total/temp);
}