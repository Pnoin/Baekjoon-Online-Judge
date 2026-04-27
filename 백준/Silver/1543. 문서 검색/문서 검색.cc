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

string x,y;
int cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin,x);
    getline(cin,y);
    for(int i=0; i<x.size(); i++){
        int ck=1;
        for(int j=0; j<y.size(); j++){
            if(x[i+j]!=y[j]){
                ck=0;
                break;
            }
        }
        cnt+=ck;
        if(ck==1){
            i+=y.size()-1;
        }
    }
    cout << cnt;
}