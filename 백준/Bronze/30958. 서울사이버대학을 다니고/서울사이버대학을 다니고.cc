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

int n,alpha[30]={},mx=0;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin.ignore();
    getline(cin,s);
    for(int i=0; i<s.size(); i++){
        if(s[i]>=97 && s[i]<=122){
            alpha[s[i]-97]++;
        }
    }
    for(int i=0; i<26; i++){
        mx=max(mx,alpha[i]);
    }
    cout << mx;
}