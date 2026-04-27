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

int n,k,dp[105][100005]={};
vector <pair<int,int>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  v.push_back({0,0});
  for(int i=0; i<n; i++){
    int x,y;
    cin >> x >> y;
    v.push_back({x,y});
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=k; j++){
      if(j-v[i].first>=0){
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i].first]+v[i].second);
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  cout << dp[n][k];
}
