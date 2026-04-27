#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005]={},cnt=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(&arr[0], &arr[n]);
  for(int i=n-1; i>=0; i--){
    if(arr[i]<cnt){
      break;
    }
    cnt++;
  }
  cout << cnt;
}
