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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        int n,arr[105]={};
        cin >> n;
        if(n==0){
            break;
        }
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        reverse(arr,arr+n);
        for(int i=0; i<n; i++){
            cout << arr[i] << '\n';
        }
        cout << 0 << '\n';
    }
}