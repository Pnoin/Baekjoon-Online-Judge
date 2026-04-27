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

int n;
pair<int,pair<int,pair<int,string>>> p[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p[i].second.second.second >> p[i].second.second.first >> p[i].second.first >> p[i].first;
    }
    sort(p,p+n);
    cout << p[n-1].second.second.second << '\n' << p[0].second.second.second;
}