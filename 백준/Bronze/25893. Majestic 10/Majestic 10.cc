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
        int a,b,c,cnt=0;
        cin >> a >> b >> c;
        cout << a <<  ' ' << b << ' ' << c << '\n';
        if(a>=10){
            cnt++;
        }
        if(b>=10){
            cnt++;
        }
        if(c>=10){
            cnt++;
        }
        if(cnt==0){
            cout << "zilch" << '\n' << '\n';
        }
        else if(cnt==1){
            cout << "double" << '\n' << '\n';
        }
        else if(cnt==2){
            cout << "double-double" << '\n' << '\n';
        }
        else if(cnt==3){
            cout << "triple-double" << '\n' << '\n';
        }
    }
}