#include <iostream>
using namespace std;

int arr[100005]={}, total[100005]={};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m; 
  total[0]=0;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
    total[i] = total[i-1] + arr[i];
  }
  for(int i=0; i<m; i++){
    int a,b; 
    cin >> a >> b;
    cout << total[b] - total[a-1] << "\n";
  }
}