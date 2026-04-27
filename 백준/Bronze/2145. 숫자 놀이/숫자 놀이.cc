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

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> n){
        if(n==0){
            break;
        }
        while(true){
            if(n<10){
                break;
            }
            int temp=0;
            while(true){
                if(n==0){
                    break;
                }
                temp+=n%10;
                n/=10;
            }
            n=temp;
        }
        cout << n << '\n';
    }
}

