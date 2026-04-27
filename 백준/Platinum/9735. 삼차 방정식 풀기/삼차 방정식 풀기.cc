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

int t;
set <long double> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for(int j=0; j<t; j++){
    long double a,b,c,d;
    cin >> a >> b >> c >> d;
    for(long double i=-2e6; i<=2e6; i++){
      if(a*i*i*i+b*i*i+c*i+d==0){
        s.insert(i);
        break;
      }
    }
    long double q=*s.begin();
    b+=a*q;
    c+=b*q;
    long double disc=b*b-(4*a*c);
    if(disc<0){
      cout << *s.begin();
      cout << '\n';
      s.clear();
      continue;
    }
    else{
      long double rtdisc=sqrt(disc);
      long double rt=((-b)+rtdisc)/(2*a);
      long double rt2=((-b)-rtdisc)/(2*a);
      s.insert(rt);
      s.insert(rt2);
    }
    for(auto i:s){
      cout << i << ' ';
    }
    cout << '\n';
    s.clear();
  }
}