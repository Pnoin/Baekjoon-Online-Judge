#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
typedef long long int ll;

vector <PII> v;

bool comp(PII a, PII b){
  if(a.second != b.second){
    return a.second > b.second;
  }
  else{
    return a.first < b.first;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int l,n,rf,rb;
  cin >> l >> n >> rf >> rb;
  for(int i=0; i<n; i++){
    int x,y;
    cin >> x >> y;
    v.push_back(make_pair(x,y));
  }
  sort(v.begin(), v.end(), comp);
  ll total=0, cur=0; 
  for(int i=0; i<n; i++){
    if(cur < v[i].first){
      total+=(v[i].first - cur)*(rf - rb)*v[i].second;
      cur=v[i].first;
    }
  }
  cout << total;
}