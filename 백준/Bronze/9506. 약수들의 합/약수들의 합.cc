#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        int n;
        cin >> n;
        if(n==-1){
            break;
        }
        int total=0;
        vector <int> v;
        v.clear();
        for(int i=1; i<=sqrt(n); i++){
            if(n%i==0){
                v.push_back(i);
                total+=i;
                if(i!=n/i){
                    v.push_back(n/i);
                    total+=(n/i);
                }
            }
        }
        total-=n;
        if(total==n){
            sort(v.begin(), v.end());
            cout << n << " = ";
            for(int i=0; i<v.size()-2; i++){
                cout << v[i] << " + ";
            }
            cout << v[v.size()-2] << '\n';
        }
        else{
            cout << n << " is NOT perfect." << '\n';
        }
    }
}