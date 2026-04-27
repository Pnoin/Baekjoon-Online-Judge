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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n==1){
        cout << '*';
        return 0;
    }
    for(int i=0; i<n-1; i++){
		cout << ' ';
    }
	cout << '*' << '\n';
    for(int i=1; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			cout << ' ';
        }
		cout << '*';
        for(int j=0; j<2*i-1; j++){
            cout << ' ';
        }
        cout << '*' << '\n';
    }
    for(int i=0; i<2*n-1; i++){
		cout << '*';
    }
}