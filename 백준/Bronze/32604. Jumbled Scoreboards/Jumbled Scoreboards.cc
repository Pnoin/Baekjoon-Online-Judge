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

int n,x=-1,y=-1,ck=1;

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
  for(int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    if(!ck){
      continue;
    }
    if(x>a || y>b){
      ck=0;
      continue;
    }
    x=a;
    y=b;
  }
  if(ck){
    cout << "yes";
  }
  else{
    cout << "no";
  } 

  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}