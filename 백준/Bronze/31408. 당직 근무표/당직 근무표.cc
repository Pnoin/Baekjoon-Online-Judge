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
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr[num]++;
    }
    int allow=(n+1)/2;
    for(int i=1; i<=100000; i++){
        if(arr[i]>allow){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
} 