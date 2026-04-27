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
typedef pair <int,int> PII;

int n;

int pseudocheck(string a){
	vector <char> v;
	int idx, sdx, cnt=0;
	for(int i=0; i<=(a.size()-1)/2; i++){
		if(a[a.size()-i-1]!=a[i]){
			idx=i;
			sdx=a.size()-i-1;
			break;
		}
	}
	for(int i=0; i<a.size(); i++){
		if(i==idx){
			continue;
		}
		v.push_back(a[i]);
	}
	for(int i=0; i<=(v.size()-1)/2; i++){
		if(v[v.size()-i-1]!=v[i]){
			cnt++;
			break;
		}
	}
	v.clear();
	for(int i=0; i<a.size(); i++){
		if(i==sdx){
			continue;
		}
		v.push_back(a[i]);
	}
	for(int i=0; i<=(v.size()-1)/2; i++){
		if(v[v.size()-i-1]!=v[i]){
			cnt++;
			break;
		}
	}
	if(cnt==2){
		return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int t=0; t<n; t++){
		string s;
		cin >> s;
		int ans=0;
		for(int j=0; j<=(s.size()-1)/2; j++){
			if(s[s.size()-j-1]!=s[j]){
				ans++;
				break;
			}
		}
		if(ans==1){
			ans+=pseudocheck(s);
		}
		cout << ans << '\n';
	}
}