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

int n,num;
vector <int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> n){
        v.clear();
        cin >> num;
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
        cout << v.size() << '\n';
    }
}