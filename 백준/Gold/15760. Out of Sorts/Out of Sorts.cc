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

vector <pair<int,int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,total=0;
	cin >> n;
	for(int i=0; i<n; i++){
	  int x;
	  cin >> x;
	  v.push_back({x,i});
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n; i++){
	  if(v[i].second>=i){
	    total=max(total,abs(i-v[i].second));
	  }
	}
	cout << total+1;
}
