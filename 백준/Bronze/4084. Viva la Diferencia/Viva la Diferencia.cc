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

ll a,b,c,d;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    while(true){
        cin >> a >> b >> c >> d;
        if(a==0 && b==0 && c==0 && d==0){
            break;
        }
        if(a==b && b==c && c==d){
            cout << 0 << '\n';
            continue;
        }
        int steps=0;
        while(!(a==b && b==c && c==d)){
            ll na=llabs(a-b),nb=llabs(b-c),nc=llabs(c-d),nd=llabs(d-a);
            a=na; 
            b=nb; 
            c=nc; 
            d=nd;
            steps++;
        }
        cout << steps << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   