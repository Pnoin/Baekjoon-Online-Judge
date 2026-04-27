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
#include <regex>
#include <deque>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

ll arr[6]={},val[6]={1,5,10,20,50,100},mx=-1,idx=0,temp=0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */

    for(int i=0; i<6; i++){
        cin >> arr[i];
    }
    for(int i=0; i<6; i++){
        ll total=arr[i]*val[i];
        if(total>mx){
            mx=total;
            temp=arr[i];
            idx=i;
        } 
        else if(total==mx){
            if(arr[i]<temp){
                temp=arr[i];
                idx=i;
            }
        }
    }
    cout << val[idx];

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

