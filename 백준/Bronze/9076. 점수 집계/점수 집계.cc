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

int n,total=0;
vector <int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        v.clear();
        total=0;
        for(int j=0; j<5; j++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        for(int j=1; j<4; j++){
            total+=v[j];
        }
        if(v[3]-v[1]>=4){
            cout << "KIN" << '\n';
        }
        else{
            cout << total << '\n';
        }
    }
}