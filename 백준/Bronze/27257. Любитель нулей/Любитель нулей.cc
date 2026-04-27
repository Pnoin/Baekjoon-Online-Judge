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

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int cnt=0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='0'){
            s[i]='A';
        }
        else{
            break;
        }
    }
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            cnt++;
        }
    }
    cout << cnt;
}