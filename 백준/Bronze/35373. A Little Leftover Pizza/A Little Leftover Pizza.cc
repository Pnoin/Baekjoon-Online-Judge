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

int n;
ll sumS=0,sumM=0,sumL=0,l,ans=0;
char s;

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
        cin >> s >> l;
        if(s=='S'){
            sumS+=l;
        }
        else if(s=='M'){
            sumM+=l;
        }
        else{
            sumL+=l;
        }
    }
    auto ceil_div=[&](ll a,ll b)->ll{
        if(a==0){
            return 0;
        }
        return (a+b-1)/b;
    };
    ans+=ceil_div(sumS,6);
    ans+=ceil_div(sumM,8);
    ans+=ceil_div(sumL,12);
    cout << ans;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

