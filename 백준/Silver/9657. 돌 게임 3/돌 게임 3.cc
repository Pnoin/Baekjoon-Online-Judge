/*
1 A 1
2 B 0
3 A 1
4 A 1
5 A 1
6 A 1
7 B 0 
8 B 0 

*/

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
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,arr[1005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    arr[1]=1;
    arr[2]=0;
    arr[3]=1;
    arr[4]=1;
    for(int i=5; i<=n; i++){
        if(arr[i-4]==1 && arr[i-3]==1 && arr[i-1]==1){
            arr[i]=0;
        }
        else{
            arr[i]=1;
        }
    }
    if(arr[n]==1){
        cout << "SK";
    }
    else{
        cout << "CY";
    }
}