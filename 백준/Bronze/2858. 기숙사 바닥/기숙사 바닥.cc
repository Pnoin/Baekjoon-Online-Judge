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

int n,m,temp=3;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while(true){
        for(int i=temp; i>2; i--){
            if((temp*i)-((i-2)*(temp-2))==n && (i-2)*(temp-2)==m){
                cout << temp << ' ' << i;
                return 0;
            }
        }
        temp++;
    }
}