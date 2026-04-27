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

int t,x,n,k;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);                
  cout.tie(NULL);
  /*
  clock_t start,finish;
  double duration;
  start=clock();
  */

  cin >> t >> x >> n;
  bool sign=false; 
  for(int i=0; i<n; i++){
    cin >> k;
    vector <int> temp_list(k);
    for(int j=0; j<k; j++){
      cin >> temp_list[j];
    }
    bool found=false;
    for(int num:temp_list){
      if(num==x){
        found=true;
        break;
      }
    }

    if(!found){
      sign=true; 
      break;
    }
  }

  if(!sign){
    cout << "YES";
  } 
  else{
    cout << "NO";
  }
  

  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}