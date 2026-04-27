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

int n, arr[1005]={}, dpasc[1005]={}, dpdesc[1005]={}, totaldp[1005]={};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i=1; i<=n; i++){
		dpasc[i]=1; 
		for(int j=i-1; j>=1; j--){
			if(arr[i]>arr[j]){
				dpasc[i]=max(dpasc[i], dpasc[j]+1);
			}
		}
	}
	for(int i=n; i>=1; i--){
		dpdesc[i]=1; 
		for(int j=n; j>i; j--){
			if(arr[i]>arr[j]){
				dpdesc[i]=max(dpdesc[i], dpdesc[j]+1);
			}
		}
	}
	for(int i=1; i<=n; i++){
		totaldp[i]=dpasc[i]+dpdesc[i]-1;
	}
	sort(totaldp, totaldp+n+1);
    cout << totaldp[n];
}