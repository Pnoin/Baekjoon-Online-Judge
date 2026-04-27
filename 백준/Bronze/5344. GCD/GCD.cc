#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n;

int GCD(int x, int y){
    int z;
    while(true){
        if(y==0){
            return x;
        }
        z=x%y;
        x=y;
        y=z;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        cout << GCD(max(x,y),min(x,y)) << '\n';
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}