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

ll n, arr[105][15]={}, md=1e9, total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        if(i==1){
            for(int j=1; j<10; j++){
                arr[i][j]=1;
            }
        }
        else{
            for(int j=0; j<10; j++){
                if(j==0){
                    arr[i][j]=arr[i-1][1]%md;
                }
                else if(j==9){
                    arr[i][j]=arr[i-1][8]%md;
                }
                else{
                    arr[i][j]=(arr[i-1][j-1]+arr[i-1][j+1])%md;
                }
            }
        }
    }
    for(int i=0; i<10; i++){
        total+=(arr[n][i]%md);
    }
    cout << total%md;
}