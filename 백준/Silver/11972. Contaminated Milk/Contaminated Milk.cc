#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>
using namespace std;

int main(){
  int n,w,d,s,person[55]={},total=0,milk[55]={},p[1005]={},m[1005]={},t[1005]={};
  cin >> n >> w >> d >> s;
  for(int i=1; i<=d; i++){
    cin >> p[i] >> m[i] >> t[i];
  }
  for(int i=1; i<=s; i++){
    int q,e;
    cin >> q >> e;
    for(int j=1; j<=d; j++){
      if(p[j]==q and t[j]<e){
        milk[m[j]]++;
      }
    }
  }
  for(int i=1; i<=50; i++){
    if(milk[i]>=s){
      memset(person,0,sizeof(person));
      int cnt=0;
      for(int j=1; j<=d; j++){
        if(m[j]==i and person[p[j]]==0){
          person[p[j]]=1;
          cnt++;
        }
      }
      total=max(total,cnt);
    }
  }
  cout << total;
}