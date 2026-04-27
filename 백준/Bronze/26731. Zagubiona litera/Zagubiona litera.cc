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

string s,a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i=0; i<a.size(); i++){
        int ck=0;
        for(int j=0; j<s.size(); j++){
            if(a[i]==s[j]){
                ck=1;
                break;
            }
        }
        if(ck==0){
            cout << a[i];
            return 0;
        }
    }
}