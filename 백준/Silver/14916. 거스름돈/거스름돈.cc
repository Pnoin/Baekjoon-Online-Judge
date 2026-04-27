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

int n,total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(true){
        if(n<=0){
            break;
        }
        if(n%5){
            total++;
            n-=2;
        }
        else{
            total+=n/5;
            break;
        }
    }
    if(n<0){
        total=-1;
    }
    cout << total;
}