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

int arr[15]={},total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<10; i++){
        cin >> arr[i];
    }
    for(int i=0; i<10; i++){
        if(total+arr[i]>=100){
            if(2*total+arr[i]<=200){
                cout << total+arr[i];
            } 
            else{
                cout << total;
            }
            return 0;
        }
        total+=arr[i];
    }
    cout << total;
}