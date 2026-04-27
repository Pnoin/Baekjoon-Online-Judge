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

int t;;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        int n;
        cin >> n;
        double total=0;
        for(int i=0; i<n; i++){
            string s;
            int num;
            double d;
            cin >> s >> num >> d;
            total+=num*d;
        }
        cout << fixed;
        cout.precision(2);
        cout << '$' << total << '\n';
    }
}