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

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string s;
        getline(cin,s);
        cout << s;
        if(s[s.size()-1]!='.'){
            cout << '.';
        }
        cout << '\n';
    }
}