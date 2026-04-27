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

int arr[500005]={}, brr[500005]={}, a, b;
vector <int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    for(int i=0; i<a; i++){
        cin >> arr[i];
    }
    for(int i=0; i<b; i++){
        cin >> brr[i];
    }
    sort(brr,brr+b);
    for(int i=0; i<a; i++){
        if(!binary_search(brr,brr+b,arr[i])){
            v.push_back(arr[i]);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
}