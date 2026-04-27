#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;

int n,c,arr[55]={};
ll total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> c;
    for(int i=0; i<n; i++){
        if(arr[i]>c){
            total+=arr[i]/c;
            if(arr[i]%c){
                total++;
            }
        }
        else if(arr[i]!=0){
            total++;
        }
    }
    cout << total*c;
}