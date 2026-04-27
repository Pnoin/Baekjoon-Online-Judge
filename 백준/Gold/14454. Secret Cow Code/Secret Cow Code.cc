#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  ll n;
  cin >> s >> n;
  n-=1;
  while(true){
    if(n < s.size()){
      break;
    }
    ll a=s.size();
    while(true){
      if(a>n){
        break;
      }
      a*=2; 
    }
    a/=2;
    n=(n-1)%a;
  }
  cout << s[n];
}