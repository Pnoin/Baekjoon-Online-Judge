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

int n,cnt=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        cout << cnt << ". ";
        n*=3;
        if(n%2){
            cout << "odd ";
            n=(n+1)/2;
        }
        else{
            cout << "even ";
            n/=2;
        }
        n*=3;
        n/=9;
        cout << n << '\n';
        cnt++;
    }
}