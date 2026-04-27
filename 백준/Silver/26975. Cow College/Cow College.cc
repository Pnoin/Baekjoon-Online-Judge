#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

vector <pair<ll,ll>> v;
ll n, arr[100005]={}, biggest=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(ll i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);
  for(ll i=0; i<n; i++){
    v.push_back(make_pair(arr[i]*(n-i),arr[i]));
    biggest=max(biggest, arr[i]*(n-i));
  }
  sort(v.begin(), v.end());
  vector <int> q;
  for(int i=0; i<v.size(); i++){
    if(v[i].first == biggest){
      q.push_back(v[i].second);
    }
  }
  sort(q.begin(), q.end());
  cout << biggest << ' ' << q[0];
}