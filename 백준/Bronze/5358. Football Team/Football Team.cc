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
    while(getline(cin,s)){
        for(int j=0; j<s.size(); j++){
            if(s[j]=='e'){
                s[j]='i';
            }
            else if(s[j]=='i'){
                s[j]='e';
            }
            else if(s[j]=='E'){
                s[j]='I';
            }
            else if(s[j]=='I'){
                s[j]='E';
            }
            cout << s[j];
        }
        cout << '\n';
    }
}