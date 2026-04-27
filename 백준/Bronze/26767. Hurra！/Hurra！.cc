#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
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
    for(int i=1; i<=n; i++){
        if(i%7==0 && i%11!=0){
            cout << "Hurra!" << '\n';
        }
        else if(i%7!=0 && i%11==0){
            cout << "Super!" << '\n';
        }
        else if(i%7==0 && i%11==0){
            cout << "Wiwat!" << '\n';
        }
        else{
            cout << i << '\n';
        }
    }
}