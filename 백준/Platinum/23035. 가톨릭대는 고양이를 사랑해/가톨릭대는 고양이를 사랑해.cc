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

int n,m,t,num,ans=0,ans2=0;
vector <pair<int,int>> temp;
vector <pair<int,int>> temp2;
vector <int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i=0; i<t; i++){
        int x,y;
        cin >> x >> y;
        if(x<=n && y<=m){
            temp.push_back({x,y});
            temp2.push_back({y,x});
        }
    }
    sort(temp.begin(), temp.end());
    sort(temp2.begin(), temp2.end());
    v.push_back(temp[0].second);
    for(int i=1; i<temp.size(); i++){
        if(temp[i].second>v[v.size()-1]){
            v.push_back(temp[i].second);
        }
        else{
            v[upper_bound(v.begin(),v.end(),temp[i].second)-v.begin()]=temp[i].second;
        }
    }
    ans=v.size();
    v.clear();
    v.push_back(temp2[0].second);
    for(int i=1; i<temp2.size(); i++){
        if(temp2[i].second>v[v.size()-1]){
            v.push_back(temp2[i].second);
        }
        else{
            v[upper_bound(v.begin(),v.end(),temp2[i].second)-v.begin()]=temp2[i].second;
        }
    }
    ans2=v.size();
    cout << max(ans,ans2);
}