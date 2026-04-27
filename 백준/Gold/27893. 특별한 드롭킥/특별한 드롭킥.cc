#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;

int n,m;
string s;
priority_queue <PII, vector <PII>, greater <PII>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> s;
  int walls=0;
  for(int i=0; i<s.size(); i++){
    if(s[i]=='X'){
      walls++;
    }
  }
  if(walls+m<=2){
    if(walls==1 && m==0){
      cout << n+1;
      return 0;
    }
    else if(walls==0 && m==1){ 
      cout << n;
      return 0;
    }
    else if(walls==1 && m==1){
      if(n==1){
          cout << n+1;
          return 0;
      }
      cout << n;
      return 0;
    }
    else if(walls==0 && m==2){
      cout << n;
      return 0;
    }
    else if(walls==0 && m==0){
      cout << n;
      return 0;
    }
  }
  else if(m>=n-walls){
    cout << 2;
    return 0;
  }
  else if(walls==0 && m>2){
    cout << n-m+2;
    return 0;
  }
  int prv;
  for(int i=0; i<s.size(); i++){
    if(s[i]=='X'){
      prv=i;
      break;
    }
  }

  for(int i=prv+1; i<s.size(); i++){
    if(s[i]=='X'){
      v.push({i-prv-1, prv});
      prv=i;
    }
  }

  while(true){
    if(v.empty() || m==0){
      break;
    }
    for(int i=v.top().second+1; i<=v.top().second+v.top().first; i++){
      s[i]='X';
      m--;
      if(m==0){
        break;
      }
    }
    v.pop();
  }
  int ans=0, temp=0;

  for(int i=0; i<s.size(); i++){
    if(s[i]=='.'){
      temp=0;
      ans++;
    }
    else{
      if(temp==0){
        ans+=2;
        temp=1;
      }
    }
  }
  cout << ans-m;
}