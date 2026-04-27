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

ll x,y;

ll cnt(ll n,int start){
	ll total=0;
	for(ll i=start; i<=n; i*=start){
    total+=n/i;
  }
	return total;
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);                
  cout.tie(NULL);
  /*
  clock_t start,finish;
  double duration;
  start=clock();
  */

  cin >> x >> y;
  cout << min(cnt(x,5)-cnt(y,5)-cnt(x-y,5),cnt(x,2)-cnt(y,2)-cnt(x-y,2));


  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}