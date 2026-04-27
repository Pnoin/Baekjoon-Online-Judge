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

int n,cnt=100,cnt2=100;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        if(x>y){
            cnt2-=x;
        }
        else if(x<y){
            cnt-=y;
        }
    }
    cout << cnt << '\n' << cnt2;
}