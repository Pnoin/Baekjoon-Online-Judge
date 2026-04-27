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

int l,d,x,n=-1,m=-1;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> l >> d >> x;
    for(int i=l; i<=d; i++){
        int sum=0,temp=i;
        while(temp>0){
            sum+=temp%10;
            temp/=10;
        }
        if(sum==x){
            if(n==-1){
                n=i;
            }
            m=i;
        }
    }
    cout << n << '\n' << m;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

