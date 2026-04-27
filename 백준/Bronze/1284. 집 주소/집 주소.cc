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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	while(true){
        int n,total=0;
        cin >> n;
        if(n==0){
            return 0;
        }
        while(true){
            if(n%10==0){
                total+=4;
            }
            else if(n%10==1){
                total+=2;
            }
            else{
                total+=3;
            }
            if(n<10){
                total+=2;
                break;
            }
            n/=10;
            total++;
        }
        cout << total << '\n';
    }
}