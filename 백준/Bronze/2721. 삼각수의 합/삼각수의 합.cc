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

int n;
ll total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        total=0;
        for(int j=1; j<=num; j++){
            ll temp=0;
            for(int k=1; k<=j+1; k++){
                temp+=k;
            }
            total+=temp*j;
        }
        cout << total << '\n';
    }
}