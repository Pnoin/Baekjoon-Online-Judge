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

int n,arr[5][10]={};

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
    string s;
    cin >> s;
    int x,y;
    if(s[1]=='m'){
      x=1;
    }
    else if(s[1]=='p'){
      x=2;
    }
    else if(s[1]=='s'){
      x=3;
    }
    else if(s[1]=='z'){
      x=4;
    }
    y=s[0]-'0';
    arr[x][y]++;
    if(arr[x][y]>4){
      cout << i+1;
      return 0;
    }
  }
  cout << 0;


  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}