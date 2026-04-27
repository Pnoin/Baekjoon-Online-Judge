#include <iostream>
using namespace std;

int main(){
  int n,dis[100005]={},oil[100005]={};
  long long total=0;
  cin >> n;
  for(int i=1; i<n; i++){
    cin >> dis[i];
  }
  for(int i=0; i<n; i++){
    cin >> oil[i];
  }
  long long m=oil[0];
  total+=m*dis[1];
  for(int i=1; i<n; i++){
    if(m<=oil[i]){
      total+=m*dis[i+1];
    }
    else{
      m=oil[i];
      total+=m*dis[i+1];
    }
  }
  cout << total;
}