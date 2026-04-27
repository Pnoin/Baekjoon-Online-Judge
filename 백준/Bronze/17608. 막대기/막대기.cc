#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int n,cnt=0,ans=0;
vector <int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << fixed;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    reverse(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(ans<v[i]){
            cnt++;
            ans=v[i];
        }
    }
    cout << cnt;
}