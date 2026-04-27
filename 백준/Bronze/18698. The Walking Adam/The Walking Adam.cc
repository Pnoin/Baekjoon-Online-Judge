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

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        string s;
        cin >> s;
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='U'){
                cnt++;
            }
            else{
                break;
            }
        }
        cout << cnt << '\n';
    }
}