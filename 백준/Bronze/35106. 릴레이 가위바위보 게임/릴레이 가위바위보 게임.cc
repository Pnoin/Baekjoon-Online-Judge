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

int n,x,cnt1=0,cnt2=0,cnt3=0;

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
    for(int i=0; i<3*n; i++){
        cin >> x;
        if(x==1){
            cnt1++;
        }
        else if(x==2){
            cnt2++;
        }
        else{
            cnt3++;
        }
    }
    int s=-1,ans=-1;
    if(cnt1==n-1){
        s=1;
    }
    if(cnt2==n-1){
        s=2;
    }
    if(cnt3==n-1){
        s=3;
    } 
    if(cnt1==n+1){
        ans=1;
    }
    if(cnt2==n+1){
        ans=2;
    }
    if(cnt3==n+1){
        ans=3;
    }
    cout << s << '\n' << ans;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

