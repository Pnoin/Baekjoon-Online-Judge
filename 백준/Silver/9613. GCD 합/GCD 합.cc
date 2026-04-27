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

int t;
vector <int> v;

int gcd(int a, int b){
	int c;
	while (b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        v.clear();
        int n;
        ll total=0;
        cin >> n;
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                total+=gcd(max(v[i],v[j]),min(v[i],v[j]));
            }
        }
        cout << total << '\n';
    }
}