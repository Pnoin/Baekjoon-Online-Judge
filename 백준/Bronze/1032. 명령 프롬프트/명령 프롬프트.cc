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
typedef long double ld;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n;
string arr[55]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<arr[0].size(); i++){
        for(int j=0; j<n; j++){
            if(arr[0][i]!=arr[j][i]){
                arr[0][i]='?';
                break;
            }
        }    
        cout << arr[0][i];    
    }
}