#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <numeric>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
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
const ld PI=acos(-1); 
const ll INF=1e18;

int l,n,arr[55]={},le=0,ri=0,ck=1; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> l;
    for(int i=0; i<l; i++){
        cin >> arr[i];
    }
    sort(arr,arr+l+1);
    cin >> n;
    for(int i=1; i<=l; i++){
        if(n==arr[i]){
            ck=0;
        }
        else if(n<arr[i]){
            le=arr[i-1]+1;
            ri=arr[i]-1;
            break;
        }
    }
    if(ck){
        cout << (n-le)*(ri-n+1)+(ri-n);
    }
    else{
        cout << 0;
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}
