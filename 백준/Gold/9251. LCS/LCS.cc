#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;
const double PI = acos(-1); 

int arr[1005][1005]={};
string x,y;
char a[1005]={},b[1005]={};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> x >> y;
  for(int i=0; i<x.size(); i++){
    a[i+1]=x[i];
  }
  for(int i=0; i<y.size(); i++){
    b[i+1]=y[i];
  }
  for(int i=1; i<=x.size(); i++){
    for(int j=1; j<=y.size(); j++){
      if(a[i]==b[j]){
        arr[i][j]=arr[i-1][j-1]+1;
      }
      else{
        arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
      }
    }
  }
  cout << arr[x.size()][y.size()];
}