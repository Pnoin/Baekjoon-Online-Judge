#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#pragma GCC optimize ("O3")
typedef long long int ll;
using namespace std;

double arr[1005]={}, total=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double n;
  cin >> n;
  for(register double i=1; i<=n; i++){
    total+=n/i;
  }
  cout.precision(10);
  cout << total;
}