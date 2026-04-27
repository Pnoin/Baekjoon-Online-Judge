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
typedef complex<double> cpx;
const double PI = acos(-1); 

int n, arr[1000005]={},visit[1000005]={},m=0;
vector <int> v;

void sieve(int x, int mx){
    for(int i=2*x; i<=mx; i+=x){
        if(visit[i]==1){
            arr[x]++;
            arr[i]--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        visit[num]=1;
        v.push_back(num);
        m=max(m,num);
    }
    for(int i=0; i<n; i++){
        sieve(v[i],m);
    }
    for(int i=0; i<v.size(); i++){
        cout << arr[v[i]] << ' ';
    }
}