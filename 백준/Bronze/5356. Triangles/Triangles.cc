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
char arr[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        int n,idx;
        char c;
        cin >> n >> c;
        idx=c-65; 
        for(int i=1; i<=n; i++){
            if(idx==26){
                idx=0; 
            }
            for(int j=0; j<i; j++){
                cout << arr[idx];
            }
            cout << '\n';
            idx++;
        }
        cout << '\n';
    }
}