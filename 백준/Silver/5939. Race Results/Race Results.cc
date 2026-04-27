#include <iostream>
#include <algorithm>
using namespace std;

struct cow{
  int hour, minute, second;
};

bool cmp(cow x, cow y){
  if(x.hour != y.hour){
    return x.hour < y.hour;
  }
  else{
    if(x.minute != y.minute){
      return x.minute < y.minute;
    }
    else{
      return x.second < y.second;
    }
  }
}

int main(){
  int n; 
  cin >> n;
  cow a[5005];
  for(int i=0; i<n; i++){
    cin >> a[i].hour >> a[i].minute >> a[i].second;
  }
  sort(&a[0], &a[n], cmp);
  for(int i=0; i<n; i++){
    cout << a[i].hour << ' ' << a[i].minute << ' ' << a[i].second << "\n";
  }
}