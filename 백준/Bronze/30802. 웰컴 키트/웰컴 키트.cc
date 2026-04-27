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

int n,x,y,arr[10]={},cnt=0;

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
    for(int i=0; i<6; i++){
        cin >> arr[i];  
    }
    cin >> x >> y;
    for(int i=0; i<6; i++){
        cnt+=arr[i]/x;
        if(arr[i]%x){
            cnt++;
        }
    }
    cout << cnt << '\n' << n/y << ' ' << n%y;
    

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
