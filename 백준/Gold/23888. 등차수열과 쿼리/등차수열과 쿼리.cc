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

ll a,d,n;

ll gcd(int x, int y){
    int z;
    while(y!=0){
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> a >> d >> n;
    ll g=gcd(max(a,d),min(a,d));
    for(int i=0; i<n; i++){
        ll ck,x,y;
        cin >> ck >> x >> y;
        if(ck==1){
            ll temp1=(y*(a+a+(d*(y-1)))/2);
            ll temp2=((x-1)*(a+a+(d*(x-2)))/2);
            cout << temp1-temp2 << '\n';
        }
        else{
            if(x==y){
                ll temp=a+(d*(x-1));
                cout << temp << '\n';
            }
            else{
                cout << g << '\n';
            }
        }
    }
}