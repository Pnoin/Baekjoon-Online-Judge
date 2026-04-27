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

int cnt=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        int n;
        vector <int> v;
        v.clear();
        cin >> n;
        if(n==0){
            break;
        }
        v.push_back(-1);
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        cout << "Case " << cnt << ": ";
        cout << fixed;
        cout.precision(1);
        if(n%2){
            cout << (double)v[n/2+1] << '\n';
        }
        else{
            cout << (double)(v[n/2]+v[n/2+1])/2 << '\n';
        }
        cnt++;
    }
}