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

int three,four,non,ans1,ans2;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);                
  cout.tie(NULL);
  /*
  clock_t start,finish;
  double duration;
  start=clock();
  */

  cin >> three >> four >> non;
  int temp3=three%3;
  if(temp3!=0){
    non-=3-temp3;
    three+=3-temp3;
  }
  if(non<0){
    cout << -1;
    return 0;
  }
  int temp4=four%4;
  if(temp4!=0){
    non-=4-temp4;
    four+=4-temp4;
  }
  if(non<0){
    cout << -1;
    return 0;
  }


  ans1=three/3;
  ans2=four/4;



  if(non%4==0){
    ans2+=non/4;
  }
  else if(non%4==3){   
    ans1++;
    ans2+=non/4;
  }
  else if(non%4==1){
    if(non<9){
      cout << -1;
      return 0;
    }
    ans1+=3;
    non-=9;
    ans2+=non/4;
  }
  else if(non%4==2){
    if(non<6){
      cout << -1;
      return 0;
    }
    ans1+=2;
    non-=6;
    ans2+=non/4;
  }
  cout << ans1 << ' ' << ans2;

  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}