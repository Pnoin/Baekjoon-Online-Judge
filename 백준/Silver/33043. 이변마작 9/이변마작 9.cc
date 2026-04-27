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

int n,ans=1e9;
vector <int> v[41];

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
  for(int i=1; i<=n; i++){
    string s;
    cin >> s;
    int x,y;
    if(s[1]=='m'){
      x=0;
    }
    else if(s[1]=='p'){
      x=1;
    }
    else if(s[1]=='s'){
      x=2;
    }
    else if(s[1]=='z'){
      x=3;
    }
    y=s[0]-'0';
    v[10*x+y].push_back(i);
  }
  for(int i=0; i<41; i++){
    if(v[i].size()>4){
      for(int j=0; j<v[i].size()-4; j++){
        ans=min(ans,v[i][j+4]-v[i][j]+1);
      }
    }
  }
  if(ans==(int)1e9){
    cout << -1;
  }
  else{
    cout << ans;
  }


  /*
  finish=clock();
  duration=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<duration<<"초";
  */
}