#include <iostream>
#include <algorithm>
using namespace std;

int a[10]={0,1,2,4,7,8,11,13,14};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t=0;
  cin >> n;
  if(n%8==0){
    cout << ((n-1)/8)*15+a[8];
  }
  else{
    cout << (n/8)*15+a[n%8];
  }
}

