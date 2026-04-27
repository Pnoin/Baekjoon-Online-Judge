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
typedef long double ld;
typedef complex<double> cpx;

int a=0,b=0,c=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<3; i++){
        string s;
        cin >> s;
        if(s[0]=='l'){
            a++;
        }
        if(s[0]=='k'){
            b++;
        }
        if(s[0]=='p'){
            c++;
        }
    }
    if(a==1 && b==1 && c==1){
        cout << "GLOBAL";
    }
    else{
        cout << "PONIX";
    }
}