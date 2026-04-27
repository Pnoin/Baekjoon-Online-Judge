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

int n;
char arr[8]={'a','b','c','d','e','f','g','h'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<8; i++){
        for(int j=1; j<=8; j++){
            if(i*8+j==n){
                cout << arr[j-1] << i+1;
            }
        }
    }
}