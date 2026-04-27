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

string s;
vector <char> x,y;
int a=0,b=0,ck=0;

int gcd(int a, int b){
    int c;
    while(true){
        if(b==0){
            break;
        }
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]==':'){
            ck=1;
            continue;
        }
        if(ck==0){
            x.push_back(s[i]);
        }
        else{
            y.push_back(s[i]);
        }
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int temp=1;
    for(int i=0; i<x.size(); i++){
        a+=temp*(x[i]-'0');
        temp*=10;
    }
    temp=1;
    for(int i=0; i<y.size(); i++){
        b+=temp*(y[i]-'0');
        temp*=10;
    }
    cout << a/gcd(a,b) << ':' << b/gcd(a,b);
}