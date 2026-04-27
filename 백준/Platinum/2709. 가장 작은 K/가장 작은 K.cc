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

int t,n;
ll arr[20]={1,9,89,89,589,3089,3089,3089,315589,315589,8128089,164378089,945628089,1922190589,11687815589,109344065589,231414378089,1452117503089,4503875315589,65539031565589};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        cout << arr[n-1] << '\n';
    }
}