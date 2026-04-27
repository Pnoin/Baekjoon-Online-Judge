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

string s,t,ans;
int idx=0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> t;
	for(int i=0; i<s.size(); i++){
	  ans+=s[i];
	  if(ans.size()>=t.size() and ans.substr(ans.size() - t.size())==t){
	    ans.resize(ans.size() - t.size());
	  }
	}
	cout << ans;
}
