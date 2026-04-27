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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  string s;
  cin >> s;
  int a=s.size(),b=0,c=0;
  for(int i=0; i<s.size(); i++){
    if(s[i]==':'){
      b++;
    }
    else if(s[i]=='_'){
      c++;
    }
  }
  cout << a+b+(c*5);
}