#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <complex>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;
const double PI = acos(-1);
typedef complex<double> cpx;

int n,arr[1005]={},num[1005]={},total=0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }
  for(int i=1; i<=n; i++){
    num[i]=1; 
    for(int j=i-1; j>=1; j--){
      if(arr[i]>arr[j]){
        num[i]=max(num[i],num[j]+1);
      }
    }
    total=max(num[i],total);
  }
  cout << total;
}