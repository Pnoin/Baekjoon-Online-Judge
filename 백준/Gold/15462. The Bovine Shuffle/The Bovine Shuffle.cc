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

int n,arr[100005]={}, visit[100005]={}, ck[100005]={}, cnt=0;

void dfs(int cur){
  visit[cur]=1; 
  if(visit[arr[cur]]==0){
    dfs(arr[cur]);
  }
  else if(ck[arr[cur]]==0){
    int temp=arr[cur];
    while(true){
      if(temp==cur){
        break;
      }
      temp=arr[temp];
      cnt++;
    }
    cnt++;
  }
  ck[cur]=1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }
  for(int i=1; i<=n; i++){
    if(visit[i]==0){
      dfs(i);
    }
  }
  cout << cnt;
}