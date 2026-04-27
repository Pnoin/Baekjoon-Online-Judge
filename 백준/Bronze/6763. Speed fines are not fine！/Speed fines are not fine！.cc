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

int a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    b-=a;
    if(b>=1 && b<=20){
        cout << "You are speeding and your fine is $100.";
    }
    else if(b>=21 && b<=30){
        cout << "You are speeding and your fine is $270.";
    }
    else if(b>30){
        cout << "You are speeding and your fine is $500.";
    }
    else{
        cout << "Congratulations, you are within the speed limit!";
    }
}