#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005]={};

int main(){
	int n, k, b, x;
	cin >> n >> k >> b;
	for(int i=0; i<100000; i++){
	  arr[i]=1;
	}
	for(int i=0; i<b; i++){
		cin >> x;
		arr[x]--;
	}
	for(int i=2; i<=n; i++){
		arr[i]+=arr[i - 1];
	}
	int mx=0;
	for(int i=k; i<=n; i++){
		mx=max(mx, arr[i] - arr[i - k]);
	}
	cout << k - mx;
}
