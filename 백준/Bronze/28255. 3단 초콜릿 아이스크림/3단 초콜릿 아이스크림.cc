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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n; 
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		float temp=s.size();
		float temp2=3.0;
		float temp3=temp/temp2;
		///cout << temp3 << '\n';
		int spSize=ceil(temp3);
		string sp=s.substr(0,spSize);
		
		string rsp=sp;
		reverse(rsp.begin(), rsp.end());
		
		string t=sp.substr(1,spSize-1);
		
		string tr=rsp.substr(1,spSize-1); 
		
		///cout << sp+rsp+sp << '\n';
		///cout << sp+tr+sp << '\n';
		///cout << sp+rsp+t << '\n';
		///cout << sp+tr+t << '\n';
		
		if(s==sp+rsp+sp){
			cout << 1 << '\n';
			continue;
		}
		if(s==sp+tr+sp){
			cout << 1 << '\n';
			continue;
		}
		if(s==sp+rsp+t){
			cout << 1 << '\n';
			continue;
		}
		if(s==sp+tr+t){
			cout << 1 << '\n';
			continue;
		}
		cout << 0 << '\n';
	}
}