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

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n==1996 || n==1997 || n==2000 || n==2007 || n==2008 || n==2013 || n==2018){
        cout << "SPbSU";
    }
    else if(n==2006){
        cout << "PetrSU, ITMO";
    }
    else{
        cout << "ITMO";
    }
} 