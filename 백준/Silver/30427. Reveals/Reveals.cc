#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
#include <map>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,m,dh=0;
string gaesori[4]={},s;
vector <pair<string,int>> v;
vector <string> notseen;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<4; i++){
        cin >> gaesori[i];
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s=="dongho"){
            dh=1;
        }
        v.push_back(make_pair(s,0));
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> s;
        for(int j=0; j<v.size(); j++){
            if(v[j].first==s){
                v[j].second=1;
            }
        }
    }
    if(dh==1){
        cout << "dongho";
        return 0;
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].second==0){
            notseen.push_back(v[i].first);
        }
    }
    if(notseen.size()==0){
        cout << "swi";
        return 0;
    }
    if(notseen.size()==1){
        cout << notseen[0];
        return 0;
    }
    sort(notseen.begin(),notseen.end());
    string ans=notseen[0];
    for(int i=0; i<notseen.size(); i++){
        if(notseen[i]=="bumin"){
            cout << "bumin";
            return 0;
        }
        else if(notseen[i]=="cake"){
            cout << "cake";
            return 0;
        }
        else if(notseen[i]=="lawyer"){
            cout << "lawyer";
            return 0;
        }
    }
    cout << ans;
} 