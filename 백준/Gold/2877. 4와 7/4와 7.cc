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
vector <int> v;

void solve (int x){
	while(true){
		if(x==0){
			break;
		}
		v.push_back(x%2);
		x/=2;
	}
	reverse(v.begin(), v.end());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	solve(n+1);
	for(int i=1; i<v.size(); i++){
		if(v[i]==0){
			cout << 4;
		}
		else{
			cout << 7;
		}
	}
}