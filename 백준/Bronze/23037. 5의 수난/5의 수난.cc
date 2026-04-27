#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;

int n,total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(true){
        if(n==0){
            break;
        }
        int temp=1;
        for(int i=0; i<5; i++){
            temp*=(n%10);
        }
        total+=temp;
        n/=10;
    }
    cout << total;
}