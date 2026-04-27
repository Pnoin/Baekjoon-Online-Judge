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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num==300){
            cout << 1 << ' ';
        }
        else if(num<300 && num>=275){
            cout << 2 << ' ';
        }
        else if(num<275 && num>=250){
            cout << 3 << ' ';
        }
        else{
            cout << 4 << ' ';
        }
    }
}