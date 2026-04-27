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

int num[3]={3,20,120},n,x=0,y=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<3; i++){
        cin >> n;
        x+=n*num[i];
    }
    for(int i=0; i<3; i++){
        cin >> n;
        y+=n*num[i];
    }
    if(x>y){
        cout << "Max";
    }
    else if(x==y){
        cout << "Draw";
    }
    else{
        cout << "Mel";
    }
}