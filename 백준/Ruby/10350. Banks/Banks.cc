#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n,arr[20005]={};
ll cnt=0,sum=0, neg=0;

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
    arr[i]+=arr[i-1];
  }
  ///http://www.salvemini.na.it/om/docs/engel.pdf
  for(int i=n+1; i<=2*n; i++) {
    arr[i]=arr[i-n]+arr[n];
  }
  for(int i=1; i<=n; i++){
    for(int j=i; j<i+n; j++){
      sum=arr[j]-arr[i-1];
      if(sum<0){
        cnt+=(abs(sum)-1)/arr[n];
        neg++;
      } 
    }
  }
  cout << cnt+neg;
}

