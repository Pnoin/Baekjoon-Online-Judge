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

int arr[5]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }
    if(arr[0]>arr[4] || arr[2]>arr[4]){
        cout << "No";
    }
    else if(arr[0]+arr[2]<=arr[4] || arr[1]>=arr[2] || arr[3]>=arr[0]){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}