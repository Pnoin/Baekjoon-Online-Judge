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

int x[15]={},parity=0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */

    for(int i=0; i<10; i++){
        cin >> x[i];
    }
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            int v=x[i] || x[j];
            if(v==1){
                parity^=1;
            }
        }
    }
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            for(int k=j+1; k<10; k++){
                int v=x[i] || x[j] || x[k];
                if(v==1){
                    parity^=1;
                }
            }
        }
    }
    cout << parity;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

