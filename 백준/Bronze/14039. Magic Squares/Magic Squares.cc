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

int a[4][4]={},target=0;
bool ok=true;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> a[i][j];
        }
    }
    for(int j=0; j<4; j++){
        target+=a[0][j];
    }
    for(int i=0; i<4; i++){
        int s=0;
        for(int j=0; j<4; j++){
            s+=a[i][j];
        }
        if(s!=target){
            ok=false;
        }
    }
    for(int j=0; j<4; j++){
        int s=0;
        for(int i=0; i<4; i++){
            s+=a[i][j];
        }
        if(s!=target){
            ok=false;
        }
    }
    if(ok){
        cout << "magic";
    } 
    else{
        cout << "not magic";
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

