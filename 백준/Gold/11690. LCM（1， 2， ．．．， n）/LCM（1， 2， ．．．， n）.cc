#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n;
bitset <100000005> arr;
ll total=1, md=4294967296;
vector <int> v;

void sieve(){
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            for(int j=i*2; j<=n; j+=i){
                arr[j]=1;
            }
            v.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    sieve();
    for(int i=0; i<v.size(); i++){
        ll temp=v[i];
        while(temp*v[i]<=n){
            temp*=v[i];
        }
        total*=temp;
        total%=md;
    }
    cout << total;
} 