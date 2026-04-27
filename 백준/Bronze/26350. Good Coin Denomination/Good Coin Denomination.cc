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
        int n,ck=0,num,prv;
        cin >> n >> num;
        cout << "Denominations: " << num << ' ';
        prv=num;
        for(int i=1; i<n; i++){
            cin >> num;
            cout << num << ' ';
            if(prv*2>num){
                ck=1;
            }
            prv=num;
        }
        cout << '\n';
        if(ck==1){
            cout << "Bad coin denominations! " << '\n' << '\n';
        }
        else{
            cout << "Good coin denominations! " << '\n' << '\n';
        }
    }
}