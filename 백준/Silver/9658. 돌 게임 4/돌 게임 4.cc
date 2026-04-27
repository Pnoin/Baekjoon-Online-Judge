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
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,arr[1005]={};

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
    arr[1]=0;
    arr[2]=1;
    arr[3]=0;
    arr[4]=1;
    arr[5]=1;
    for(int i=6; i<=n; i++){
        if(arr[i-1]==1 && arr[i-3]==1 && arr[i-4]==1){
            arr[i]=0;
        }
        else{
            arr[i]=1;
        }
    }
    if(arr[n]){
        cout << "SK";
    }
    else{
        cout << "CY";
    }


    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
