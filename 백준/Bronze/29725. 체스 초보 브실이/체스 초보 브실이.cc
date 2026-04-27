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

char n;
int totalw=0,totalb=0;

int val(char c){
    if(c=='.' || c=='K' || c=='k'){
        return 0;
    }
    if(c=='P' || c=='p'){
        return 1;
    }
    if(c=='N' || c=='n'){
        return 3;
    }
    if(c=='B' || c=='b'){
        return 3;
    }
    if(c=='R' || c=='r'){
        return 5;
    }
    if(c=='Q' || c=='q'){
        return 9;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> n;
            if(n<=90){
                totalw+=val(n);
            }
            else{
                totalb+=val(n);
            }
        }
    }
    cout << totalw-totalb;
}