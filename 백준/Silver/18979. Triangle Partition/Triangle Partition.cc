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

int t,n,order_arr[300005]={};
ll xs[300005]={},ys[300005]={};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n;
        for(int i=0; i<3*n; i++){
            cin >> xs[i] >> ys[i];
            order_arr[i]=i;
        }
        sort(order_arr,order_arr+3*n,[](int a,int b){
            if(xs[a]<xs[b]){
                return true;
            }
            if(xs[a]>xs[b]){
                return false;
            }
            return ys[a]<ys[b];
        });
        for(int i=0; i<n; i++){
            cout << order_arr[3*i]+1 << ' ' << order_arr[3*i+1]+1 << ' ' << order_arr[3*i+2]+1 << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   