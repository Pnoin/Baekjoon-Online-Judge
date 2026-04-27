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

int n,k,arr[1005]={},cnt=0;

void sieve(){
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            for(int j=i; j<=n; j+=i){
                if(arr[j]==0){
                    cnt++;
                }
                arr[j]=1;
                if(cnt==k){
                    cout << j;
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    sieve();   
}
