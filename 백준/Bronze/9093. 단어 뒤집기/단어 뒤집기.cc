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

int n;
vector <char> v;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin.ignore();
	for(int i=0; i<n; i++){
		getline(cin,s);
		for(int j=0; j<s.size(); j++){
			if(s[j]==' '){
				reverse(v.begin(), v.end());
				for(int k=0; k<v.size(); k++){
					cout << v[k];
				}
				cout << ' ';
				v.clear();
			}
			else{
				v.push_back(s[j]);
				if(j==s.size()-1){
				  reverse(v.begin(), v.end());
  				for(int k=0; k<v.size(); k++){
  					cout << v[k];
  				}
  				v.clear();
				}
			}
		}
		cout << '\n';
	}
}