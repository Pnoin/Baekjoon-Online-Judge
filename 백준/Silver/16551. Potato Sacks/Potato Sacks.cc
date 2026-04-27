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

int p;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> p;
    for(int test=0; test<p; test++){
        int k,cap,w[10]={},ok=0;        
        cin >> k >> cap;
        for(int i=0; i<10; i++){
            cin >> w[i];
        }
        for(int mask=0; mask<(1<<10); mask++){
            int sum=0;
            for(int i=0; i<10; i++){
                if(mask&(1<<i)){
                    sum+=w[i];
                }
            }
            if(sum==cap){
                ok=true;
                break;
            }
        }
        cout << k << ' ';
        if(ok){
            cout << "YES" << '\n';
        } 
        else{
            cout << "NO" << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   