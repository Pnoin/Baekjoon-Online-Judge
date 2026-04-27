#include <iostream>
#include <algorithm>
using namespace std;

int n, lo=1, hi=1, total=0, sum=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while(true){
    if(hi > n+1 or lo > hi){
      break;
    }
    if(sum < n){
      sum+=hi;
      hi++;
    }
    else if(sum == n){
      total++;
      sum+=hi;
      hi++;
    }
    else{
      sum-=lo;
      lo++;
    }
  }
  cout << total;
}