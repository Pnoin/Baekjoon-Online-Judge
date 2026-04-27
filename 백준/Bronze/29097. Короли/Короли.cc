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

int n,m,k,a,b,c;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> m >> k >> a >> b >> c;
    int j=n*a,r=m*b,s=k*c,mx=max({j,r,s});
    vector <string> ans;
    if(j==mx){
        ans.push_back("Joffrey");
    }
    if(r==mx){
        ans.push_back("Robb");
    }
    if(s==mx){
        ans.push_back("Stannis");
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   