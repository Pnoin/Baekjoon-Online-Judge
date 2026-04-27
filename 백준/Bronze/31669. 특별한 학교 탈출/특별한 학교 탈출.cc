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

int n,m;
char arr[105][105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=m; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(arr[j][i]=='X'){
                cnt++;
            }
        }
        if(cnt==n){
            cout << i;
            return 0;
        }
    }
    cout << "ESCAPE FAILED";
}