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

ll n,p,sumM=0,sumJ=0,cntM=0,cntJ=0;
char c;

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
        cin >> c >> p;
        if(c=='M'){
            sumM+=p;
            cntM++;
        }
        else{
            sumJ+=p;
            cntJ++;
        }
    }
    if(cntM==0 && cntJ==0){
        cout << 'V';
        return 0;
    }
    if(cntM==0){
        if(sumJ==0){
            cout << 'V';
        }
        else{
            cout << 'J';
        }
        return 0;
    }
    ll left=sumM*cntJ,right=sumJ*cntM;
    if(left>right){
        cout << 'M';
    }
    else if(left<right){
        cout << 'J';
    }
    else{
        cout << 'V';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

