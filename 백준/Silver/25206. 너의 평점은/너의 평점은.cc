#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> pll;

string ran[9]={"A+","A0","B+","B0","C+","C0","D+","D0","F"};
double arr[9]={4.5,4.0,3.5,3.0,2.5,2.0,1.5,1.0,0.0},total=0,temp=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<20; i++){
        string s,m;
        double n;
        cin >> s >> n >> m;
        if(m=="P"){
            continue;
        }
        temp+=n;
        for(int j=0; j<9; j++){
            if(m==ran[j]){
                total+=n*arr[j];
                break;
            }
        }
    }
    cout << total/temp;
}