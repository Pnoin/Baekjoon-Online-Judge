#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  int num;
  cin >> num;
  vector <int> c;
  vector <int> r;
  for(int i=0; i<num; i++){
    int x,y;
    cin >> x >> y;
    if(x==0){
      c.push_back(y);
    }
    else{
      r.push_back(y);
    }
  }
  c.push_back(m);
  r.push_back(n);
  sort(r.begin(),r.end());
  sort(c.begin(),c.end());
  vector <int> a;
  vector <int> b;
  a.push_back(r[0]);
  b.push_back(c[0]);
  for(int i=1; i<r.size(); i++){
    a.push_back(r[i]-r[i-1]);
  }
  for(int i=1; i<c.size(); i++){
    b.push_back(c[i]-c[i-1]);
  }
  sort(a.begin(),a.end(),greater<>());
  sort(b.begin(),b.end(),greater<>());
  cout << a[0]*b[0];
}