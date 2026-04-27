#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  if(n%4==1 || n%4==3){
    cout << "SK";
  }
  else{
    cout << "CY";
  }
}