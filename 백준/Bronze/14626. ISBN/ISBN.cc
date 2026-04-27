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

string s;
int missing=-1,sum=0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> s;
    for(int i=0; i<12; i++){
        if(s[i]=='*'){
            missing=i;
        }
    }
    for(int i=0; i<12; i++){
        if(i==missing){
            continue;
        }
        int digit=s[i]-'0',w=(i%2==0?1:3);
        sum+=digit*w;
    }
    int m=s[12]-'0',wm=(missing%2==0?1:3);
    int t=(-(sum+m)%10+10)%10,inv=(wm==1?1:7);
    cout << (inv*t)%10;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   