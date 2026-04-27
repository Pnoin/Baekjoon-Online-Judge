#include <iostream>
using namespace std;

int a[100005][3]={};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, max = 0;
  char q;
  cin >> n;
  for(int i=0; i<3; i++){
    a[0][i]=0;
  }
  for(int i=1; i<=n; i++){
    cin >> q;
    for(int j=0; j<3; j++){
      a[i][j] = a[i-1][j];
    }
    if(q=='P'){
      a[i][0]=a[i-1][0]+1;
    }
    else if(q=='H'){
      a[i][1]=a[i-1][1]+1;
    }
    else{
      a[i][2]=a[i-1][2]+1;
    }
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      for(int k=1; k<=n; k++){
        if(a[k][i]+a[n][j]-a[k][j] > max){
          max = a[k][i]+a[n][j]-a[k][j];
        }
      }
    }
  }
  cout << max;
}