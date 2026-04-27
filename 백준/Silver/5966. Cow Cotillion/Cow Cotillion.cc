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

int t, n; 
vector <char> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t; 
	for(int i=0; i<t; i++){
	  v.clear();
	  cin >> n; 
	  for(int j=0; j<n; j++){
	    char c;
	    cin >> c;
	    v.push_back(c);
	  }
	  int left=0,right=0,temp=0;
	  for(int j=0; j<n; j++){
	    if(v[j]=='<'){
	      right++;
	    }
	    else if(v[j]=='>'){
	      left++;
	    }
	    if(left<right){
	      temp=1; 
	      break;
	    }
	  }
	  if(left!=right){
	    temp=1;
	  }
	  if(temp==1){
	    cout << "illegal" << '\n';
	  }
	  else{
	    cout << "legal" << '\n';
	  }
	}
}
