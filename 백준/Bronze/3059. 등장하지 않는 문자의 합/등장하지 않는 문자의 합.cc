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

int t,total=0,visit[30]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        memset(visit,0,sizeof(visit));
        total=0;
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            if(visit[s[i]-65]==0){
                visit[s[i]-65]=1;
            }
        }
        for(int i=0; i<26; i++){
            if(visit[i]==0){
                total+=i+65;
            }
        }
        cout << total << '\n';
    }
}