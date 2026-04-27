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

int arr[10]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i==j){
                continue;
            }
            if(arr[i]==arr[j]){
                arr[i]=-1;
                arr[j]=-1;
            }
        }
    }
    for(int i=0; i<5; i++){
        if(arr[i]!=-1){
            cout << arr[i];
            return 0;
        }
    }
}