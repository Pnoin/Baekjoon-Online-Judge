#include <iostream>
using namespace std;

int arr[100005]={}, a[100005]={}, b[100005]={}, c[100005]={};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  a[0]=0;
  b[0]=0;
  c[0]=0;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
    a[i]=a[i-1];
    b[i]=b[i-1];
    c[i]=c[i-1];
    if(arr[i]==1){
      a[i]++;
    }
    else if(arr[i]==2){
      b[i]++;
    }
    else{
      c[i]++;
    }
  }
  for(int i=0; i<q; i++){
    int x,y;
    cin >> x >> y;
    cout << a[y] - a[x-1] << ' ' << b[y] - b[x-1] << ' ' << c[y] - c[x-1] << "\n";
  }
}