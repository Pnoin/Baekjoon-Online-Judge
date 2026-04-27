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

int a,b,c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0){
            break;
        }
        if(b-a==c-b){
            cout << "AP " << c+c-b << '\n';
        }
        else{
            cout << "GP " << c+((c-b)*(c-b)/(b-a)) << '\n';
        }
    }
}