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

int t,arr[10]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        for(int i=0; i<8; i++){
            cin >> arr[i];
        }
        arr[0]+=arr[4];
        if(arr[0]<1){
            arr[0]=1;
        }
		arr[1]+=arr[5];
        if(arr[1]<1){
            arr[1]=1;
        }
		arr[2]+=arr[6];
        if(arr[2]<0){
            arr[2]=0;
        }
		arr[3]+=arr[7];
        cout << arr[0]+(arr[1]*5)+(arr[2]*2)+(arr[3]*2) << '\n';
    }
}