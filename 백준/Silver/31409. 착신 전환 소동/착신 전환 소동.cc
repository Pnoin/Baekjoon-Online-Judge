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

int n,arr[100005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(arr[i]==i){
            cnt++;
            if(i==1){
                arr[i]=n;
            }
            else{
                arr[i]=i-1;
            }
        }
    }
    cout << cnt << '\n';
    for(int i=1; i<=n; i++){
        cout << arr[i] << ' ';
    }
} 