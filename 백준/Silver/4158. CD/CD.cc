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

int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n >> m;
        if(n==0 && m==0){
            break;
        }
        vector <int> v;
        v.clear();
        int cnt=0;
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        for(int i=0; i<m; i++){
            int num;
            cin >> num;
            if(binary_search(v.begin(),v.end(),num)){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
} 