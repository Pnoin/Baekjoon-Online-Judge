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

int t,n,m,num;
vector <int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=1; test<=t; test++){
        v.clear();
        cin >> n >> m >> num;
        v.push_back(num);
        for(int i=1; i<n; i++){
            cin >> num;
            if(num>v[v.size()-1]){
                v.push_back(num);
            }
            else{
                v[lower_bound(v.begin(),v.end(),num)-v.begin()]=num;
            }
        }
        if(v.size()>=m){
            cout << "Case #" << test << '\n' << 1 << '\n';
        }
        else{
            cout << "Case #" << test << '\n' << 0 << '\n';
        }
    }
}