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

int n,x,a=-1,b=-1,total=0,arr[4]={};

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
    cin >> x;
    arr[x]++;
  }
  int temp=min(arr[0],arr[3]),temp2=min(arr[1],arr[2]);
  arr[0]-=temp;
  arr[1]-=temp2;
  arr[2]-=temp2;
  arr[3]-=temp;
  total+=(temp+temp2)*3;
  for(int i=0; i<4; i++){
    if(arr[i]){
      if(a==-1){
        a=i;
      }
      else{
        b=i;
      }
    }
  }
  if(b==-1){
    cout << total;
  }
  else{
    total+=min(arr[a],arr[b])*(a^b);
    cout << total;
  }

  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}