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
vector <ll> ff, ss, ans;

void to_one(ll a, ll b){
  while(true){
    ff.push_back(a);
    if(a==1){
      break;
    }
    if(a%2==0){
      a/=2;
    }
    else{
      a++;
    }
  }
  while(true){
    ss.push_back(b);
    if(b==1){
      break;
    }
    if(b%2==0){
      b/=2;
    }
    else{
      b--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for(int i=0; i<t; i++){
    ll x,y;
    cin >> x >> y;
    ff.clear();
    ss.clear();
    ans.clear();
    to_one(x,y);
    for(int j=0; j<ff.size(); j++){
      for(int k=0; k<ss.size(); k++){
        if(ff[j]<=ss[k]){
          ans.push_back(j+k+ss[k]-ff[j]);
        }
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << '\n';
  }
}