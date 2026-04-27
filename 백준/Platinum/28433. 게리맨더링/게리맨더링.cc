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

int t,n;
vector <ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n;
        v.clear();
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            if(num!=0){
                v.push_back(num);
            }
        }
        if(v.size()==0){
            cout << "NO" << '\n';
            continue;
        }
        int pcnt=0,ncnt=0;
        for(int i=0; i<v.size()-1; i++){
            if(v[i]<0){
                if(v[i+1]<0 || v[i]+v[i+1]>0){
                    v[i+1]+=v[i];
                    v[i]=0;
                }
            }
            else if(v[i]>0 && v[i+1]<0 && v[i]+v[i+1]>0){
                v[i+1]+=v[i];
                v[i]=0;
            }
        }
        for(int i=0; i<v.size(); i++){
            if(v[i]<0){
                ncnt++;
            }
            else if(v[i]>0){
                pcnt++;
            }
        }
        if(pcnt>ncnt){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
} 