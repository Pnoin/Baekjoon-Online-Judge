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

double x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x >> y;
    x/=y;
    if(x<0.2){
        cout << "weak";
    }
    else if(x>=0.2 && x<0.4){
        cout << "normal";
    }
    else if(x>=0.4 && x<0.6){
        cout << "strong";
    }
    else{
        cout << "very strong";
    }
}