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

int r=0,b=0,arr[8]{10,8,6,5,4,3,2,1};
string s;
char c;
vector <pair<string,char>> v;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    for(int i=0; i<8; i++){
        cin >> s >> c;
        v.push_back({s,c});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<8; i++){
        if(v[i].second=='R')
            r+=arr[i];
        else
            b+=arr[i];
    }
    if(r>b){
        cout << "Red";
    }
    else if(r<b){
        cout << "Blue";
    }
    else if(v[0].second=='R'){
        cout << "Red";
    }
    else{
        cout << "Blue";
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}
