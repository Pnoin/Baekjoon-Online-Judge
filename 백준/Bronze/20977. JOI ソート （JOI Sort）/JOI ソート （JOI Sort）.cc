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

int n;
char arr[105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]=='J'){
            arr[i]='A';
        }
        else if(arr[i]=='O'){
            arr[i]='B';
        }
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++){
        if(arr[i]=='A'){
            cout << 'J';
        }
        else if(arr[i]=='B'){
            cout << 'O';
        }
        else{
            cout << arr[i];
        }
    }
}