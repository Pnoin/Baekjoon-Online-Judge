#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  pair <int, int> arr[100005];
  for(int i=0; i<n; i++){
    cin >> arr[i].first >> arr[i].second;
  }
  sort(&arr[0], &arr[n]);
  for(int i=0; i<n; i++){
    cout << arr[i].first << ' ' << arr[i].second << "\n";
  }
}