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
    getline(cin,s);
    if(s.size()<=2){
        cout << "CE";
        return 0;
    }
    if(s[0]=='"' && s[s.size()-1]=='"'){
        for(int i=1; i<s.size()-1; i++){
            cout << s[i];
        }
    }
    else{
        cout << "CE";
    }
}