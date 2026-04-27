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

string x1="fdsajkl;",x2="jkl;fdsa",b="asdf;lkj",y2=";lkjasdf",z="asdfjkl;",a=";lkjfdsa",s; 

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
  if(s==x1 || s==x2){
    cout << "in-out";
  }
  else if(s==b || s==y2){
    cout << "out-in";
  }
  else if(s==z){
    cout << "stairs";
  }
  else if(s==a){
    cout << "reverse";
  }
  else{
    cout << "molu";
  }

  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}