#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n,m,arr[100005]={},total=0,mx=0,mx2=0;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> arr[0];
	for(int i=1; i<n; i++){
	  cin >> arr[i];
	  arr[i]+=arr[i-1];
	}
	for(int i=m-1; i<n; i++){
	  mx=min(mx, arr[i-m]);
	  mx2=max(mx2, arr[i]-mx);
	}
	cout << mx2;
}
