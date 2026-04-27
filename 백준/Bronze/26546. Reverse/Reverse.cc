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

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        string s;
        int a,b;
        cin >> s >> a >> b;
        for(int i=0; i<s.size(); i++){
            if(i>=a && i<b){
                continue;
            }
            cout << s[i];
        }
        cout << '\n';
    }
}