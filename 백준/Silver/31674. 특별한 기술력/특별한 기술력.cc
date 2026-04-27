#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

ll n,arr[200005]={},sum=0,md=1e9+7,mul=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++){
        ll temp=arr[i]%md;
        sum+=(temp*mul)%md;
        sum%=md;
        mul*=2;
        mul%=md;
    }
    cout << sum;
}