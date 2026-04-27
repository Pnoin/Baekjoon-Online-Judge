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

int n, num, mx=0;

vector <pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        v.push_back({num,i});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        mx=max(mx,v[i].second-i);
    }
    cout << mx+1;
}