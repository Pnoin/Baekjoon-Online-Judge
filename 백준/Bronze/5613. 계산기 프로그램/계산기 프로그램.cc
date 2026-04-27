#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
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
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 
const ll INF = 1e18;

int n,ck=0;
string a,b;

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
    while(true){
        cin >> a;
        if(a=="="){
            break;
        }
        if(isdigit(a[0])){
            if(b=="+"){
                n+=stoi(a);
            }
            else if(b == "-"){
                n -= stoi(a);
            }
            else if(b=="*"){
                n*=stoi(a);
            }
            else if(b=="/"){
                n/=stoi(a);
            }
        }
        else{
            b=a;
        }
    }
 
    cout << n;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}
