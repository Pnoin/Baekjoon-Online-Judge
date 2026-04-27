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
typedef __int128_t li;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

int t,a,b;
string arr[6]={"Yakk","Doh","Seh","Ghar","Bang","Sheesh"},same[6]={"Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh"};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> t;
    for(int test=1; test<=t; test++){
        cin >> a >> b;
        a--;
        b--;
        cout << "Case " << test << ": ";
        if(a==b){
            cout << same[a] << '\n';
        }
        else{
            if(min(a,b)==4 && max(a,b)==5){
                cout << "Sheesh Beesh" << '\n';
                continue;
            }
            cout << arr[max(a,b)] << ' ' << arr[min(a,b)] << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   