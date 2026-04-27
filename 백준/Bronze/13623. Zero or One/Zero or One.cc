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

int a,b,c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    if(a!=b && a!=c){
        cout << 'A';
    }
    else if(b!=a && b!=c){
        cout << 'B';
    }
    else if(c!=a && c!=b){
        cout << 'C';
    }
    else{
        cout << '*';
    }
} 