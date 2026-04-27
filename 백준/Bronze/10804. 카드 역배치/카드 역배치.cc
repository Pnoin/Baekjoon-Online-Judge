//https://oeis.org/A348479
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
#include <random>
#include <time.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int arr[25]={},x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<=20; i++){
        arr[i]=i;
    }
    for(int i=0; i<10; i++){
        cin >> x >> y;
        reverse(arr+x,arr+y+1);
    }
    for(int i=1; i<=20; i++){
        cout << arr[i] << ' ';
    }
}