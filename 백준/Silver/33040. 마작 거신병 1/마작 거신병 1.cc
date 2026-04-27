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

int h,w,c,d,mn=0,mx,arr[100005]={};

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);                
  cout.tie(NULL);
  /*
  clock_t start,finish;
  double duration;
  start=clock();
  */

  cin >> h >> w >> c >> d;
  if(h>=w+2){
    cout << -1;
    return 0;
  }
  for(int i=0; i<h; i++){
    mn+=i;
    arr[i]=i;
  }
  mx=h*w-mn;
  if(d>mx || d<mn){
    cout << -1;
    return 0;
  }
  d-=mn;
  int temp=w;
  for(int i=h-1; i>=0; i--){
    if(d<temp-arr[i]){
      arr[i]+=d;
      break;
    }
    else{
      d-=temp-arr[i];
      arr[i]=temp;
      temp--;
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<arr[i]; j++){
      cout << 9 << ' ';
    }
    for(int j=0; j<w-arr[i]; j++){
      cout << 1 << ' ';
    }
    cout << '\n';
  }

  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}