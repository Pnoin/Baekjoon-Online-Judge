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

int n,total=0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    if(s=="Poblano"){
      total+=1500;
    }
    else if(s=="Mirasol"){
      total+=6000;
    }
    else if(s=="Serrano"){
      total+=15500;
    }
    else if(s=="Cayenne"){
      total+=40000;
    }
    else if(s=="Thai"){
      total+=75000;
    }
    else if(s=="Habanero"){
      total+=125000;
    }
  }
  cout << total;
}
