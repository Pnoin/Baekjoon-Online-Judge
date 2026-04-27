#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n;
vector <int> v[130000];
char c[130000]={};
int num[130000]={};

ll dfs(int cur){
  if(v[cur].size()==0){
    if(c[cur]=='W'){
      return 0;
    }
    else if(c[cur]=='S'){
      return num[cur];
    }
  }
  ll total=0;
  for(int i=0; i<v[cur].size(); i++){
    total+=dfs(v[cur][i]);
  }
  if(c[cur]=='S'){
    total+=num[cur];
  }
  else if(c[cur]=='W'){
    total-=num[cur];
  }
  if(total<0){
    return 0;
  }
  else{
    return total;
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
  for(int i=2; i<=n; i++){
    int x;
    cin >> c[i] >> num[i] >> x;
    v[x].push_back(i);
  }
  cout << dfs(1);
}
