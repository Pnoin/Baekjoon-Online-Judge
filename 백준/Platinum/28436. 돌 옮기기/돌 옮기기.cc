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

int n;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        ll temp=0,total=0;
        char now='.';
        int ck=0;
        for(int j=s.size()-1; j>=0; j--){
            if(now=='.'){
                if(s[j]!='.'){
                    now=s[j];
                }
                else{
                    continue;
                }
            }
            if(s[j]=='.'){
                if(now=='W'){
                    total+=temp;
                } 
                else{
                    total-=temp;  
                }
            } 
            else if(s[j]==now){
                temp++;
            } 
            else{
                now='.';
                temp=0;  
            }
        }
        if(total>0){
            cout << "WHITE" << '\n';
        }
        else{
            cout << "BLACK" << '\n';
        }
    }
} 