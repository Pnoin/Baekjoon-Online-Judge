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

ll n,m,total=0,temp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> m;
    temp=n-(n%100);
    while(true){
        if((temp+total)%m==0 || total>=100){
            break;
        }
        total++;
    }
    if(total<10){
        cout << 0;
    }
    cout << total;
}