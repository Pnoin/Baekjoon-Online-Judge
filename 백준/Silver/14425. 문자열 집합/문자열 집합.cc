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
typedef long double ld;
typedef complex<double> cpx;
typedef __float128 lf;
const lf PI=3.14159265358979323846264338327950288419716939937510Q;

int n,m,cnt=0;
vector <string> v;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<m; i++){
        cin >> s; 
        if(binary_search(v.begin(),v.end(),s)){
            cnt++;
        }
    }
    cout << cnt;
}