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

int n,m,arr[100005]={},brr[100005]={};

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);                
  cout.tie(NULL);
  /*
  clock_t start,finish;
  double duration;
  start=clock();
  */

  cin >> n >> m;
  arr[1]=1;
  brr[2]=1;
  for(int i=3; i<=n; i++){
    arr[i]=arr[i-1]+arr[i-2];
    brr[i]=brr[i-1]+brr[i-2];
  }
  for(int i=1; i<=m; i++){
    if((m-(arr[n]*i))%brr[n]==0){
      cout << i << '\n' << (m-(arr[n]*i))/brr[n];
      return 0;
    }
  }


  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}