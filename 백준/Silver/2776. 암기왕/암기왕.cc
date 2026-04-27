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

int t,n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n;
        vector <int> v;
        v.clear();
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        cin >> m;
        for(int i=0; i<m; i++){
            int num;
            cin >> num;
            if(binary_search(v.begin(),v.end(),num)){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
    }
} 