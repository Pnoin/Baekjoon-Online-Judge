// = conway's soldiers interactive game

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int n,ans[5]={1,2,4,8,20};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num>4){
            cout << "frogger" << '\n';
        }
        else{
            cout << ans[i] << '\n';
        }
    }
}