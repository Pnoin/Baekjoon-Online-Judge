#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;

int x[3]={},y[3]={},ans;

void ccw(){
  ans=(y[2]-y[0])*(x[1]-x[0])-(y[1]-y[0])*(x[2]-x[0]);
  if(ans>0){
    ans=1;
  }
  else if(ans<0){
    ans=-1;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for(int i=0; i<3; i++){
    cin >> x[i] >> y[i];
  }
  ccw();
  cout << ans;
}