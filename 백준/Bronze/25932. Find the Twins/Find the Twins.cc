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
        int z=0,m=0;
        for(int i=0; i<10; i++){
            int num;
            cin >> num;
            cout << num << ' ';
            if(num==17){
                z=1;
            }
            if(num==18){
                m=1;
            }
        }
        cout << '\n';
        if(z==0 && m==0){
            cout << "none" << '\n';
        }
        else if(z==1 && m==0){
            cout << "zack" << '\n';
        }
        else if(z==0 && m==1){
            cout << "mack" << '\n';
        }
        else if(z==1 && m==1){
            cout << "both" << '\n';
        }
        cout << '\n';
    }
}