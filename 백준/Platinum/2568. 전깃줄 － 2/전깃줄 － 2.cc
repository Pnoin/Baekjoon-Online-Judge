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

int n,dp[100005]={};
vector <int> v;
pair <int,int> p[100005];

int bisect(int x, int vsize){
    int lo=0, hi=vsize-1;
    while(true){
        if(lo>=hi){
            break;
        }
        int md=(hi+lo)/2;
        if(v[md]<x){
            lo=md+1;
        }
        else{
            hi=md;
        }
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n);
    v.push_back(p[0].second);
    dp[0]=1;
    for(int i=1; i<n; i++){
        if(p[i].second>v[v.size()-1]){
            v.push_back(p[i].second);
            dp[i]=v.size();
        }
        else{
            int idx=bisect(p[i].second,v.size());
            ///cout << idx << '\n'; 
            v[idx]=p[i].second;
            dp[i]=idx+1;
        }
    }
    cout << n-v.size() << '\n';
    int temp=v.size();
    v.clear();
    for(int i=n-1; i>=0; i--){
        if(dp[i]==temp){
            temp--;
        }
        else{
            v.push_back(p[i].first);
        }
    }
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << '\n';
    }
}