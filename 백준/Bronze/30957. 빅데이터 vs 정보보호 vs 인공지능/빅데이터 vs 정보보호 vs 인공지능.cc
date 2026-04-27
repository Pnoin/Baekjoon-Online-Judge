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
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,alpha[3]={},mx=0;
string s;
char y[3]={'B','S','A'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    for(int i=0; i<n; i++){
        if(s[i]=='B'){
            alpha[0]++;
        }
        else if(s[i]=='S'){
            alpha[1]++;
        }
        else{
            alpha[2]++;
        }
    }
    mx=max(max(alpha[0],alpha[1]),alpha[2]);
    if(alpha[0]==alpha[1] && alpha[1]==alpha[2]){
        cout << "SCU";
    }
    else{
        for(int i=0; i<3; i++){
            if(alpha[i]==mx){
                cout << y[i];
            }
        }
    }
}