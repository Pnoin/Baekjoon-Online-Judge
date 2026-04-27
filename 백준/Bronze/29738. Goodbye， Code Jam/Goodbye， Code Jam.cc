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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        if(temp>4500){
            cout << "Case #" << i << ": Round 1" << '\n';
        }
        else if(temp>1000){
            cout << "Case #" << i << ": Round 2" << '\n';
        }
        else if(temp>25){
            cout << "Case #" << i << ": Round 3" << '\n';
        }
        else{
            cout << "Case #" << i << ": World Finals" << '\n';
        }
    }
}