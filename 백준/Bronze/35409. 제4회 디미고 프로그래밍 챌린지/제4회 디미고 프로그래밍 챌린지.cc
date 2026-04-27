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

int h,m;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> h >> m;
    int temp=h*100+m;
    if(630<=temp && temp<=900){
        cout << "Yes";
    }
    else if(950<=temp && temp<=1000){
        cout << "Yes";
    }
    else if(1050<=temp && temp<=1100){
        cout << "Yes";
    }
    else if(1150<=temp && temp<=1200){
        cout << "Yes";
    }
    else if(1250<=temp && temp<=1350){
        cout << "Yes";
    }
    else if(1440<=temp && temp<=1450){
        cout << "Yes";
    }
    else if(1540<=temp && temp<=1550){
        cout << "Yes";
    }
    else if(1640<=temp && temp<=2250){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

