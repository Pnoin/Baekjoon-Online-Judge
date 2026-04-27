#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;

int n,arr[3]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[j];
        }
        sort(arr,arr+3);
        cout << "Case #" << i << ": ";
        if(arr[0]+arr[1]<=arr[2]){
            cout << "invalid!" << '\n';
        }
        else if(arr[0]==arr[1] && arr[1]==arr[2]){
            cout << "equilateral" << '\n';
        }
        else if(arr[0]==arr[1] || arr[1]==arr[2] || arr[2]==arr[0]){
            cout << "isosceles" << '\n';
        }
        else{
            cout << "scalene" << '\n';
        }
    }
}