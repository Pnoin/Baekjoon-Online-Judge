#include <iostream>
#include <algorithm>
using namespace std;

int num[200005] = {}, ck[100005] = {}, n, k, lo = 0, hi = -1, mx = 0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for(int i=0; i<n; i++){
    cin >> num[i];
  }
  while (true) {
    if (hi + 1 == n) {   
      break;
    }
    if(ck[num[hi+1]] < k) {    
      ck[num[hi+1]]++;
      hi++;
    }
    else{
      ck[num[lo]]--;
      lo++;
    }
    mx = max(mx, hi-lo+1);
  }
  cout << mx;
}