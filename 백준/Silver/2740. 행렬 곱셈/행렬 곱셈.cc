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

int n,m,x,y,arr[105][105]={},brr[105][105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> x >> y;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin >> brr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<y; j++){
            int temp=0;
            for(int k=0; k<x; k++){
                temp+=arr[i][k]*brr[k][j];
            }
            cout << temp << ' ';
        }
        cout << '\n';
    }
}