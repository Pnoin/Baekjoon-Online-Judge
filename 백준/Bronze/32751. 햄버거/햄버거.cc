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

int n,a,b,c,d;
string s;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> a >> b >> c >> d >> s;
    if(s[0]!='a' || s[s.size()-1]!='a'){
        cout << "No";
        return 0;
    }
    for(int i=1; i<n; i++){
        if(s[i-1]==s[i]){
            cout << "No";
            return 0;
        }
    }

    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            a--;
        }
        else if(s[i]=='b'){
            b--;
        }
        else if(s[i]=='c'){
            c--;
        }
        else if(s[i]=='d'){
            d--;
        }
    }
    if(a>=0 && b>=0 && c>=0 && d>=0){
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
