#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<3; i++){
        cin >> s;
        int cnt=1,mx=1;
        for(int j=0; j<s.size()-1; j++){
            if(s[j]==s[j+1]){
                cnt++;
            }
            else{
                mx=max(mx,cnt);
                cnt=1;
            }
        }
        mx=max(mx,cnt);
        cout << mx << '\n';
    }
}