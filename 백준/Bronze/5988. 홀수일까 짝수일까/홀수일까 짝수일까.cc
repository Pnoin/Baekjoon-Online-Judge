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
        cin >> s;
        char c=s[s.size()-1];
        if(c=='0' || c=='2' || c=='4' || c=='6' || c=='8'){
            cout << "even" << '\n';
        }
        else{
            cout << "odd" << '\n';
        }
    }
}